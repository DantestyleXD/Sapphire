// FFXIVTheMovie.ParserV3
// id hint used:
//ACTOR12 = ACTOR12
//SCENE_50 = ACTOR12
//ACTOR13 = null
//ACTOR14 = null
//ACTOR15 = null
//ACTOR16 = null
//ACTOR17 = null
//ACTOR18 = null
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse606 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse606() : Sapphire::ScriptAPI::EventScript( 65954 ){}; 
  ~GaiUse606() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_3, 2 entries
  //SEQ_4, 18 entries
  //SEQ_5, 24 entries
  //SEQ_255, 8 entries

  //ACTIONTIMELINEEVENTLINK = 1002
  //ACTOR0 = 1010961
  //ACTOR1 = 1009057
  //ACTOR10 = 1010974
  //ACTOR11 = 1010975
  //ACTOR12 = 1010976
  //ACTOR13 = 1010969
  //ACTOR14 = 1010962
  //ACTOR15 = 1010963
  //ACTOR16 = 1010964
  //ACTOR17 = 1010965
  //ACTOR18 = 1010966
  //ACTOR19 = 1010967
  //ACTOR2 = 1001821
  //ACTOR20 = 1010968
  //ACTOR3 = 1006454
  //ACTOR4 = 1010977
  //ACTOR5 = 1011624
  //ACTOR6 = 1010970
  //ACTOR7 = 1010971
  //ACTOR8 = 1010972
  //ACTOR9 = 1010973
  //CUTSCENEN01 = 709
  //ENEMY0 = 5607264
  //ENEMY1 = 5607265
  //ENEMY10 = 5607216
  //ENEMY11 = 5607217
  //ENEMY2 = 5607266
  //ENEMY3 = 5607269
  //ENEMY4 = 5607271
  //ENEMY5 = 5607272
  //ENEMY6 = 5607212
  //ENEMY7 = 5607213
  //ENEMY8 = 5607214
  //ENEMY9 = 5607215
  //EOBJECT0 = 2005062
  //EOBJECT1 = 2005061
  //EVENTRANGE0 = 5607357
  //EVENTRANGE1 = 5607356
  //LOCSE01 = 42

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU
        break;
      }
      case 1:
      {
        if( actor == 1009057 || actorId == 1009057 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
            // +Callback Scene00003: Normal(CutScene), id=unknown
          }
        }
        if( actor == 1010961 || actorId == 1010961 ) // ACTOR0 = TATARU
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=TATARU
        }
        if( actor == 1001821 || actorId == 1001821 ) // ACTOR2 = BARTHOLOMEW
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=BARTHOLOMEW
        }
        break;
      }
      case 2:
      {
        if( actor == 1009057 || actorId == 1009057 ) // ACTOR1 = ALPHINAUD
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD
          }
        }
        if( actor == 1001821 || actorId == 1001821 ) // ACTOR2 = BARTHOLOMEW
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=BARTHOLOMEW
        }
        break;
      }
      case 3:
      {
        if( actor == 1006454 || actorId == 1006454 ) // ACTOR3 = MARCELAIN
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MARCELAIN
          }
        }
        if( actor == 1009057 || actorId == 1009057 ) // ACTOR1 = ALPHINAUD
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 4:
      {
        if( actor == 5607357 || actorId == 5607357 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00010( player ); // Scene00010: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5607264 || actorId == 5607264 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 5607265 || actorId == 5607265 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 5607266 || actorId == 5607266 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 5607269 || actorId == 5607269 ) // ENEMY3 = unknown
        {
          // empty entry
        }
        if( actor == 5607271 || actorId == 5607271 ) // ENEMY4 = unknown
        {
          // empty entry
        }
        if( actor == 5607272 || actorId == 5607272 ) // ENEMY5 = unknown
        {
          // empty entry
        }
        if( actor == 2005062 || actorId == 2005062 ) // EOBJECT0 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
          // +Callback Scene00012: Normal(None), id=unknown
        }
        if( actor == 1010977 || actorId == 1010977 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        if( actor == 1011624 || actorId == 1011624 ) // ACTOR5 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(None), id=unknown
        }
        if( actor == 1010970 || actorId == 1010970 ) // ACTOR6 = unknown
        {
          Scene00015( player ); // Scene00015: Normal(None), id=unknown
        }
        if( actor == 1010971 || actorId == 1010971 ) // ACTOR7 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1010972 || actorId == 1010972 ) // ACTOR8 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 1010973 || actorId == 1010973 ) // ACTOR9 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
        }
        if( actor == 1010974 || actorId == 1010974 ) // ACTOR10 = unknown
        {
          Scene00019( player ); // Scene00019: Normal(None), id=unknown
        }
        if( actor == 1010975 || actorId == 1010975 ) // ACTOR11 = unknown
        {
          Scene00020( player ); // Scene00020: Normal(None), id=unknown
          // +Callback Scene00021: Normal(None), id=unknown
          // +Callback Scene00022: Normal(None), id=unknown
        }
        if( actor == 1010976 || actorId == 1010976 ) // ACTOR12 = unknown
        {
          Scene00023( player ); // Scene00023: Normal(None), id=unknown
          // +Callback Scene00024: Normal(None), id=unknown
          // +Callback Scene00025: Normal(None), id=unknown
        }
        if( actor == 1006454 || actorId == 1006454 ) // ACTOR3 = MARCELAIN
        {
          Scene00026( player ); // Scene00026: Normal(None), id=unknown
          // +Callback Scene00027: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        break;
      }
      case 5:
      {
        if( actor == 5607356 || actorId == 5607356 ) // EVENTRANGE1 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 6 )
          {
            Scene00028( player ); // Scene00028: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 5607212 || actorId == 5607212 ) // ENEMY6 = unknown
        {
          // empty entry
        }
        if( actor == 5607213 || actorId == 5607213 ) // ENEMY7 = unknown
        {
          // empty entry
        }
        if( actor == 5607214 || actorId == 5607214 ) // ENEMY8 = unknown
        {
          // empty entry
        }
        if( actor == 5607215 || actorId == 5607215 ) // ENEMY9 = unknown
        {
          // empty entry
        }
        if( actor == 5607216 || actorId == 5607216 ) // ENEMY10 = unknown
        {
          // empty entry
        }
        if( actor == 5607217 || actorId == 5607217 ) // ENEMY11 = unknown
        {
          // empty entry
        }
        if( actor == 2005061 || actorId == 2005061 ) // EOBJECT1 = unknown
        {
          Scene00029( player ); // Scene00029: Normal(None), id=unknown
          // +Callback Scene00030: Normal(None), id=unknown
        }
        if( actor == 1010969 || actorId == 1010969 ) // ACTOR13 = unknown
        {
          Scene00031( player ); // Scene00031: Normal(None), id=unknown
        }
        if( actor == 1010962 || actorId == 1010962 ) // ACTOR14 = unknown
        {
          Scene00032( player ); // Scene00032: Normal(None), id=unknown
        }
        if( actor == 1010963 || actorId == 1010963 ) // ACTOR15 = unknown
        {
          Scene00033( player ); // Scene00033: Normal(None), id=unknown
        }
        if( actor == 1010964 || actorId == 1010964 ) // ACTOR16 = unknown
        {
          Scene00034( player ); // Scene00034: Normal(None), id=unknown
        }
        if( actor == 1010965 || actorId == 1010965 ) // ACTOR17 = unknown
        {
          Scene00035( player ); // Scene00035: Normal(None), id=unknown
        }
        if( actor == 1010966 || actorId == 1010966 ) // ACTOR18 = unknown
        {
          Scene00036( player ); // Scene00036: Normal(None), id=unknown
        }
        if( actor == 1010967 || actorId == 1010967 ) // ACTOR19 = unknown
        {
          Scene00037( player ); // Scene00037: Normal(None), id=unknown
        }
        if( actor == 1010968 || actorId == 1010968 ) // ACTOR20 = unknown
        {
          Scene00038( player ); // Scene00038: Normal(None), id=unknown
        }
        if( actor == 1010970 || actorId == 1010970 ) // ACTOR6 = unknown
        {
          Scene00039( player ); // Scene00039: Normal(None), id=unknown
        }
        if( actor == 1010971 || actorId == 1010971 ) // ACTOR7 = unknown
        {
          Scene00040( player ); // Scene00040: Normal(None), id=unknown
        }
        if( actor == 1010972 || actorId == 1010972 ) // ACTOR8 = unknown
        {
          Scene00041( player ); // Scene00041: Normal(None), id=unknown
        }
        if( actor == 1010973 || actorId == 1010973 ) // ACTOR9 = unknown
        {
          Scene00042( player ); // Scene00042: Normal(None), id=unknown
        }
        if( actor == 1010974 || actorId == 1010974 ) // ACTOR10 = unknown
        {
          Scene00043( player ); // Scene00043: Normal(None), id=unknown
          // +Callback Scene00044: Normal(None), id=unknown
        }
        if( actor == 1010975 || actorId == 1010975 ) // ACTOR11 = unknown
        {
          Scene00045( player ); // Scene00045: Normal(None), id=unknown
          // +Callback Scene00046: Normal(None), id=unknown
          // +Callback Scene00047: Normal(None), id=unknown
        }
        if( actor == 1010976 || actorId == 1010976 ) // ACTOR12 = ACTOR12
        {
          Scene00048( player ); // Scene00048: Normal(None), id=unknown
          // +Callback Scene00049: Normal(None), id=unknown
          // +Callback Scene00050: Normal(None), id=ACTOR12
        }
        if( actor == 1006454 || actorId == 1006454 ) // ACTOR3 = MARCELAIN
        {
          Scene00051( player ); // Scene00051: Normal(Talk, TargetCanMove), id=MARCELAIN
        }
        break;
      }
      case 255:
      {
        if( actor == 1006454 || actorId == 1006454 ) // ACTOR3 = MARCELAIN
        {
          Scene00052( player ); // Scene00052: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MARCELAIN
        }
        if( actor == 1010962 || actorId == 1010962 ) // ACTOR14 = unknown
        {
          Scene00053( player ); // Scene00053: Normal(None), id=unknown
        }
        if( actor == 1010963 || actorId == 1010963 ) // ACTOR15 = unknown
        {
          Scene00054( player ); // Scene00054: Normal(None), id=unknown
        }
        if( actor == 1010964 || actorId == 1010964 ) // ACTOR16 = unknown
        {
          Scene00055( player ); // Scene00055: Normal(None), id=unknown
        }
        if( actor == 1010965 || actorId == 1010965 ) // ACTOR17 = unknown
        {
          Scene00056( player ); // Scene00056: Normal(None), id=unknown
        }
        if( actor == 1010966 || actorId == 1010966 ) // ACTOR18 = unknown
        {
          Scene00057( player ); // Scene00057: Normal(None), id=unknown
        }
        if( actor == 1010967 || actorId == 1010967 ) // ACTOR19 = unknown
        {
          Scene00058( player ); // Scene00058: Normal(None), id=unknown
        }
        if( actor == 1010968 || actorId == 1010968 ) // ACTOR20 = unknown
        {
          Scene00059( player ); // Scene00059: Normal(None), id=unknown
        }
        break;
      }
      default:
      {
        player.sendUrgent( "Sequence {} not defined.", player.getQuestSeq( getId() ) );
        break;
      }
    }
  }

public:
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 0, 0 );
  }

  void onEmote( uint64_t actorId, uint32_t eventId, uint32_t emoteId, Entity::Player& player ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    onProgress( player, actorId, actor, 1, emoteId );
  }

  void onBNpcKill( uint32_t npcId, Entity::Player& player ) override
  {
    onProgress( player, npcId, 0, 2, 0 );
  }

  void onWithinRange( Entity::Player& player, uint32_t eventId, uint32_t param1, float x, float y, float z ) override
  {
    onProgress( player, param1, param1, 3, param1 );
  }

private:
  void checkProgressSeq0( Entity::Player& player )
  {
    player.updateQuest( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 2 );
    }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 4 );
    }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 6 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 6 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00001( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00004: Normal(Talk, TargetCanMove), id=TATARU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00005: Normal(Talk, TargetCanMove), id=BARTHOLOMEW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00006: Normal(Talk, FadeIn, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 6, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00007: Normal(Talk, TargetCanMove), id=BARTHOLOMEW" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00008: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00009: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00010: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 6 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00011: Normal(None), id=unknown" );
    Scene00012( player );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00012: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00014: Normal(None), id=unknown" );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00015: Normal(None), id=unknown" );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00018: Normal(None), id=unknown" );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00019: Normal(None), id=unknown" );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00020: Normal(None), id=unknown" );
    Scene00021( player );
  }
  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00021: Normal(None), id=unknown" );
    Scene00022( player );
  }
  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchChain]Scene00022: Normal(None), id=unknown" );
  }

  void Scene00023( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00023: Normal(None), id=unknown" );
    Scene00024( player );
  }
  void Scene00024( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00024: Normal(None), id=unknown" );
    Scene00025( player );
  }
  void Scene00025( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchChain]Scene00025: Normal(None), id=unknown" );
  }

  void Scene00026( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00026: Normal(None), id=unknown" );
    Scene00027( player );
  }
  void Scene00027( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00027: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 27, NONE, callback );
  }

  void Scene00028( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00028: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 6 );
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 28, NONE, callback );
  }

  void Scene00029( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00029: Normal(None), id=unknown" );
    Scene00030( player );
  }
  void Scene00030( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00030: Normal(None), id=unknown" );
    checkProgressSeq5( player );
  }

  void Scene00031( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00031: Normal(None), id=unknown" );
  }

  void Scene00032( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00032: Normal(None), id=unknown" );
  }

  void Scene00033( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00033: Normal(None), id=unknown" );
  }

  void Scene00034( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00034: Normal(None), id=unknown" );
  }

  void Scene00035( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00035: Normal(None), id=unknown" );
  }

  void Scene00036( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00036: Normal(None), id=unknown" );
  }

  void Scene00037( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00037: Normal(None), id=unknown" );
  }

  void Scene00038( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00038: Normal(None), id=unknown" );
  }

  void Scene00039( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00039: Normal(None), id=unknown" );
  }

  void Scene00040( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00040: Normal(None), id=unknown" );
  }

  void Scene00041( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00041: Normal(None), id=unknown" );
  }

  void Scene00042( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00042: Normal(None), id=unknown" );
  }

  void Scene00043( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00043: Normal(None), id=unknown" );
    Scene00044( player );
  }
  void Scene00044( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00044: Normal(None), id=unknown" );
  }

  void Scene00045( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00045: Normal(None), id=unknown" );
    Scene00046( player );
  }
  void Scene00046( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00046: Normal(None), id=unknown" );
    Scene00047( player );
  }
  void Scene00047( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchChain]Scene00047: Normal(None), id=unknown" );
  }

  void Scene00048( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00048: Normal(None), id=unknown" );
    Scene00049( player );
  }
  void Scene00049( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchTrue]Scene00049: Normal(None), id=unknown" );
    Scene00050( player );
  }
  void Scene00050( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling [BranchChain]Scene00050: Normal(None), id=ACTOR12" );
  }

  void Scene00051( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00051: Normal(Talk, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 51, NONE, callback );
  }

  void Scene00052( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00052: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=MARCELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 52, NONE, callback );
  }

  void Scene00053( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00053: Normal(None), id=unknown" );
  }

  void Scene00054( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00054: Normal(None), id=unknown" );
  }

  void Scene00055( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00055: Normal(None), id=unknown" );
  }

  void Scene00056( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00056: Normal(None), id=unknown" );
  }

  void Scene00057( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00057: Normal(None), id=unknown" );
  }

  void Scene00058( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00058: Normal(None), id=unknown" );
  }

  void Scene00059( Entity::Player& player )
  {
    player.sendDebug( "GaiUse606:65954 calling Scene00059: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( GaiUse606 );