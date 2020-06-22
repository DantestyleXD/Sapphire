// This is an automatically generated C++ script template
// SapphireTheMovieQuestReparser.ParserV2

#include "Manager/TerritoryMgr.h"
#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: ManFst404_00519
// Quest Name: Lady of the Vortex
// Quest ID: 66055
// Start NPC: 1006492
// End NPC: 1006730

using namespace Sapphire;

class ManFst404 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AH
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      Seq3 = 3,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto Actor0 = 1006492;
//    static constexpr auto Actor1 = 1000106;
//    static constexpr auto Actor2 = 1007690;
//    static constexpr auto Actor4 = 1006730;
//    static constexpr auto Actor5 = 1004433;
//    static constexpr auto ContentStart = 20003;
//    static constexpr auto CutScene01 = 104;
//    static constexpr auto CutScene02 = 105;
//    static constexpr auto CutScene03 = 106;
//    static constexpr auto CutScene04Wol = 107;
//    static constexpr auto CutScene05 = 372;
//    static constexpr auto CutSceneAfter01 = 108;
//    static constexpr auto CutSceneAfter02 = 286;
//    static constexpr auto Instancedungeon0 = 20003;
//    static constexpr auto Poprange0 = 4103392;
//    static constexpr auto Poprange1 = 4313619;
//    static constexpr auto Poprange2 = 4332853;
//    static constexpr auto Poprange3 = 4103351;
//    static constexpr auto ScreenImageUnlock = 115;
//    static constexpr auto Territorytype0 = 132;
//    static constexpr auto Territorytype1 = 331;
//    static constexpr auto Territorytype2 = 130;
//    static constexpr auto UnlockAddNewContentToCf = 3702;

  public:
    ManFst404() : Sapphire::ScriptAPI::EventScript( 66055 ){}; 
    ~ManFst404() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
switch( player.getQuestSeq( getId() ) ){
case 0:{
//if( actor == 1006492 && player.getQuestUI8AL( getId() ) != 1 ) { Scene?????( player ); }
//if( actor == 1000106 ) { Scene?????( player ); }
Scene00000( player );
break;
}
case 1:{
//ACTOR2, UI8AL, 1, -2, False
if( actor == 1007690 && player.getQuestUI8AL( getId() ) != 1 ) { Scene00002( player ); }
//ACTOR0, null, 0, -2, False
if( actor == 1006492 ) { Scene00003( player ); }
//ACTOR1, null, 0, -2, False
if( actor == 1000106 ) { Scene00004( player ); }
break;
}
case 2:{
//ACTOR2, null, 0, -2, False
if( actor == 1007690 ) { Scene00005( player ); }
break;
}
case 3:{
Scene00006( player );
break;
}
case 255:{
//ACTOR4, null, 0, -2, False
if( actor == 1006730 ) { Scene00008( player ); }
//ACTOR5, null, 0, -2, False
if( actor == 1004433 ) { Scene00009( player ); }
break;
}
default: { player.sendUrgent( "seq {} not defined.", player.getQuestSeq( getId() ) ); break; }
}
  }


  private:
  //////////////////////////////////////////////////////////////////////
  // Available Scenes in this quest, not necessarly all are used
  void Scene00000( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
if( result.param2 == 1 )
Scene00001( player );
    };
player.sendDebug( "questId: {}, calling Talk, QuestOffer, QuestAccept:Scene00000 +1 ", getId() );

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 1 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](0)CutScene:Scene00001 ", getId() );

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
if( result.param2 == 1 ){
player.setQuestUI8AL( getId(), 1 );
if( player.getQuestUI8AL( getId() ) == 1 ){
player.setQuestUI8AL( getId(), 0 );
player.updateQuest( getId(), 2 );
}
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00002 ACTOR2:UI8AL=-2, 1", getId() );

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR0
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk:Scene00003 ACTOR0", getId() );

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR1
//does not modify quest vars
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00004 ACTOR1", getId() );

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR2
//no valid quest var detected
if( result.param2 == 1 ){
player.updateQuest( getId(), 3 );
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00005 ACTOR2", getId() );

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
{ Scene00007( player ); }
    };
player.sendDebug( "questId: {}, calling Talk:Scene00006 +1 ", getId() );

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
player.updateQuest( getId(), 255 );
    };
player.sendDebug( "questId: {}, calling [sub:CombinedCutScene](6)CutScene:Scene00007 ", getId() );

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR4
if( result.param2 == 1 ){
if( player.giveQuestRewards( getId(), result.param3 ) ) player.finishQuest( getId() );
}
    };
player.sendDebug( "questId: {}, calling Talk, QuestReward, QuestComplete:Scene00008 ACTOR4", getId() );

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
//Target: ACTOR5
//no valid quest var detected
if( result.param2 == 1 ){
//next scene not found
}
    };
player.sendDebug( "questId: {}, calling Talk, YesNo:Scene00009 ACTOR5", getId() );

    player.playScene( getId(), 9, NONE, callback );
  }

};

EXPOSE_SCRIPT( ManFst404 );
