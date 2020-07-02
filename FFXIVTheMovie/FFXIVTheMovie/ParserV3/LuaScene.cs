﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FFXIVTheMovie.ParserV3
{
    public class LuaScene
    {
        public static LuaScene ParseLuaCode(List<string> codeBlock, int sceneNum)
        {
            if (sceneNum == 10)
            {
                int a = 1;
            }
            LuaScene result = new LuaScene(sceneNum);
            if (codeBlock.Count > 0)
            {
                var argList = codeBlock[0].ExtractFuncArgsFromLuaFuncDef();
                if (argList.Count < 3)
                    throw new Exception($"[LuaScene]Invalid arg list.");
                string varFramework = argList[0], varPlayer = argList[1], varTarget = argList[2];
                Dictionary<string, string> localVarTable = null;
                foreach (var s in codeBlock)
                {
                    var line = s;
                    if (line.StartsWith("function ") || line == "end" || line == "else")
                    {
                        continue;
                    }
                    else if (line.StartsWith("local "))
                    {
                        if (localVarTable != null)
                            throw new Exception($"[LuaScene]Local var table already parsed.");
                        localVarTable = new Dictionary<string, string>();
                        var localDef = line.Substring(5).Split(',');
                        foreach (var localVar in localDef)
                        {
                            localVarTable.Add(localVar.Trim(), null);
                        }
                        continue;
                    }

                    if (line[0] == 'L' && line.IndexOf("=") >= 0)
                    {
                        var varName = line.GetStringBetween(null, "=");
                        var varValue = line.GetStringBetween("=", null);
                        string[] varNames = null;
                        string[] varValues = null;
                        if (varName.Contains(','))
                        {
                            varNames = varName.Split(',');
                            varValues = varValue.Split(',');
                        }
                        else
                        {
                            varNames = new string[] { varName };
                            varValues = new string[] { varValue };
                        }
                        if (varNames.Length != varValues.Length)
                        {
                            throw new Exception($"[LuaScene]Unexpected local var def, check script.");
                        }
                        for (int i = 0; i < varNames.Length; i++)
                        {
                            varNames[i] = varNames[i].Trim();
                            varValues[i] = varValues[i].Trim();
                            if (localVarTable.ContainsKey(varNames[i]))
                            {
                                localVarTable[varNames[i]] = varValues[i].ExpandLocalVar(localVarTable);
                            }
                            else
                            {
                                throw new Exception($"[LuaScene]Unknown local var {varNames[i]}.");
                            }
                        }
                        continue;
                    }

                    if (line.StartsWith("if "))
                    {
                        line = line.GetStringBetween("if ", "then");
                    }

                    if (line.StartsWith("return "))
                    {
                        line = line.Substring(7);
                        if (line[0] == '(')
                        {
                            line = line.Substring(1, line.Length - 2);
                        }
                        var returnVarList = line.ToVarList();
                        if (returnVarList.Count == 0)
                            throw new Exception($"[LuaScene]Empty return line.");
                        foreach (var r in returnVarList)
                        {
                            var f = ParseLuaFunction(r.ExpandLocalVar(localVarTable));
                            if (f != null)
                            {
                                result.FunctionList.Add(f);
                            }
                        }
                        continue;
                    }

                    var luaFunction = ParseLuaFunction(line.ExpandLocalVar(localVarTable));
                    if (luaFunction != null)
                    {
                        result.FunctionList.Add(luaFunction);
                        continue;
                    }
                }

                foreach (var f in result.FunctionList)
                {
                    if (FuncNameToSceneTypeTable.ContainsKey(f.FuncName))
                    {
                        var type = FuncNameToSceneTypeTable[f.FuncName];
                        if (result.Type != SceneType.Normal && result.Type != type)
                            throw new Exception($"[LuaScene]Multiple scene type detected at Scene{sceneNum}.");
                        result.Type = type;
                        if (result.Type == SceneType.NpcTrade && f.FuncName == "NpcTrade")
                        {
                            Dictionary<string, int> itemTable = new Dictionary<string, int>();
                            for (int i = 4; i < f.ArgList.Count; i += 3)
                            {
                                if (f.ArgList[i] != "0,")
                                {
                                    itemTable.Add(f.ArgList[i].GetStringBetween($"{varFramework}.", null), int.Parse(f.ArgList[i + 1]));
                                }
                            }
                            result.TypeParam1 = itemTable;
                        }
                    }
                    if (FuncNameToSceneElementTable.ContainsKey(f.FuncName))
                    {
                        var element = FuncNameToSceneElementTable[f.FuncName];
                        if ((element & SceneElement.Talk) > 0 && f.VarName == varTarget)
                        {
                            var textArg = f.ArgList.FirstOrDefault(a => a.Contains($"{varFramework}.TEXT_"));
                            if (textArg != null)
                            {
                                var text = textArg.ExpandLocalVar(localVarTable).GetStringBetween($"{varFramework}.", null);
                                var tmp = text == null ? null : text.Split('_');
                                if (tmp != null)
                                {
                                    if (tmp.Length == 6)
                                    {
                                        var identity = tmp[3];
                                        if (result.Identity != "unknown" && result.Identity != identity)
                                            throw new Exception($"[LuaScene]Multiple scene identity detected at Scene{sceneNum}");
                                        result.Identity = identity;
                                    }
                                }
                            }
                        }
                        result.Element |= element;
                    }
                    if ((f.FuncName == "ScenarioMessage" || f.FuncName == "LogMessage") && (f.ArgList[0].Contains("_POP_MESSAGE") || f.ArgList[0].Contains("_POPMESSAGE")))
                    {
                        result.Element |= SceneElement.PopBNpc;
                    }
                    if (f.FuncName == "WaitForTransparency" && f.VarName == varTarget)
                    {
                        result.Element |= SceneElement.NpcDespawn;
                    }
                    if ((f.FuncName == "PlayActionTimeline" || f.FuncName == "TurnTo" || f.FuncName == "LookAt" || f.FuncName == "WalkOut") && f.VarName == varTarget)
                    {
                        result.Element |= SceneElement.TargetCanMove;
                    }
                }
            }
            return result;
        }
        private static LuaFunctionCall ParseLuaFunction(string line)
        {
            bool usingDot = false;
            int index = line.IndexOf(':');
            if (index < 0)
            {
                index = line.IndexOf('.');
                usingDot = true;
            }
            if (index > 0 && line[0] == 'A' && line.IndexOf('(') > 0 && line.IndexOf(')') > 0)
            {
                var varName = line.Substring(0, index);
                var funcName = line.GetStringBetween(usingDot ? "." : ":", "(");
                var argDef = line.GetStringBetween("(", ")");
                var luaFunction = new LuaFunctionCall();
                luaFunction.VarName = varName;
                luaFunction.FuncName = funcName;
                luaFunction.ArgList = argDef.ToVarList();
                return luaFunction;
            }
            return null;
        }

        public static Dictionary<string, SceneType> FuncNameToSceneTypeTable = new Dictionary<string, SceneType>();
        public static Dictionary<string, SceneElement> FuncNameToSceneElementTable = new Dictionary<string, SceneElement>();
        static LuaScene()
        {
            FuncNameToSceneTypeTable.Add("NpcTrade", SceneType.NpcTrade);
            FuncNameToSceneTypeTable.Add("SetNpcTradeItem", SceneType.NpcTrade);

            FuncNameToSceneElementTable.Add("FadeIn", SceneElement.FadeIn);
            FuncNameToSceneElementTable.Add("PlayCutScene", SceneElement.CutScene);
            FuncNameToSceneElementTable.Add("YesNo", SceneElement.YesNo);
            FuncNameToSceneElementTable.Add("YesNoQuestBattle", SceneElement.YesNo | SceneElement.QuestBattle);
            FuncNameToSceneElementTable.Add("ScenarioMessage", SceneElement.Message);
            FuncNameToSceneElementTable.Add("LogMessage", SceneElement.Message);
            FuncNameToSceneElementTable.Add("Talk", SceneElement.Talk);
            FuncNameToSceneElementTable.Add("Inventory", SceneElement.Inventory);
            FuncNameToSceneElementTable.Add("QuestOffer", SceneElement.QuestOffer);
            FuncNameToSceneElementTable.Add("QuestAccepted", SceneElement.QuestAccept);
            FuncNameToSceneElementTable.Add("QuestCompleted", SceneElement.QuestComplete);
            FuncNameToSceneElementTable.Add("QuestReward", SceneElement.QuestReward);
            FuncNameToSceneElementTable.Add("Dismount", SceneElement.Dismount);
            FuncNameToSceneElementTable.Add("PlayQuestGimmickReaction", SceneElement.QuestGimmickReaction);
        }
        public int SceneNumber;
        public string SceneFunctionName => $"Scene{SceneNumber:00000}";
        public List<LuaFunctionCall> FunctionList = new List<LuaFunctionCall>();
        public SceneType Type;
        public object TypeParam1;
        public object TypeParam2;
        public SceneElement Element;
        public string Identity = "unknown";
        public bool IsIdentityCompatible(string id)
        {
            return id == "unknown" || this.Identity == "unknown" || this.Identity == id;
        }
        public enum SceneType
        {
            Normal = 0,
            NpcTrade = 5,
        }

        [Flags]
        public enum SceneElement
        {
            None = 0,
            Talk = 1,
            CutScene = 1 << 1,
            QuestBattle = 1 << 2,
            YesNo = 1 << 3,
            Message = 1 << 4,
            Inventory = 1 << 5,
            NpcDespawn = 1 << 6,
            FadeIn = 1 << 7,
            QuestOffer = 1 << 8,
            QuestAccept = 1 << 9,
            QuestReward = 1 << 10,
            QuestComplete = 1 << 11,
            PopBNpc = 1 << 12,
            TargetCanMove = 1 << 13,
            Dismount = 1 << 14,
            QuestGimmickReaction = 1 << 15,
        }

        public override string ToString()
        {
            return $"{SceneFunctionName}: {Type}({Element}), id={Identity}";
        }

        private LuaScene(int sceneNum)
        {
            this.SceneNumber = sceneNum;
        }

        public class LuaFunctionCall
        {
            public string VarName;
            public string FuncName;
            public List<string> ArgList = new List<string>();

            public override string ToString()
            {
                return $"{VarName}.{FuncName}()";
            }
        }
    }
}