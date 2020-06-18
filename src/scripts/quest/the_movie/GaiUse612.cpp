// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: GaiUse612_00424
// Quest Name: The Least among Us
// Quest ID: 65960
// Start NPC: 1010984
// End NPC: 1010897

using namespace Sapphire;

class GaiUse612 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL

    // Steps in this quest ( 0 is before accepting, 
    // 1 is first, 255 means ready for turning it in
    enum Sequence : uint8_t
    {
//      Seq0 = 0,
//      Seq1 = 1,
//      Seq2 = 2,
//      SeqFinish = 255,
    };

    // Entities found in the script data of the quest
//    static constexpr auto ActionTimelineBattleCorpse = 73;
//    static constexpr auto ActionTimelineEventActionEnd = 82;
//    static constexpr auto ActionTimelineEventActionLoop = 81;
//    static constexpr auto ActionTimelineEventActionStart = 80;
//    static constexpr auto ActionTimelineEventBaseFrightened = 983;
//    static constexpr auto ActionTimelineEventBaseFrightened2 = 985;
//    static constexpr auto ActionTimelineEventBaseGuardStand = 808;
//    static constexpr auto ActionTimelineEventBaseTalkMemo = 923;
//    static constexpr auto ActionTimelineFacialFear = 614;
//    static constexpr auto Actor0 = 1010984;
//    static constexpr auto Actor1 = 1010988;
//    static constexpr auto Actor2 = 1010897;
//    static constexpr auto Actor3 = 1010989;
//    static constexpr auto Actor4 = 1010990;
//    static constexpr auto Actor5 = 1010991;
//    static constexpr auto Actor6 = 1011614;
//    static constexpr auto Eobject0 = 2005068;
//    static constexpr auto EventActionWatchguardMiddle = 56;
//    static constexpr auto LocActor0 = 5607545;
//    static constexpr auto LocActor1 = 1009412;
//    static constexpr auto LocActor2 = 1009413;
//    static constexpr auto LocActor3 = 1011648;
//    static constexpr auto LocActor4 = 1011617;
//    static constexpr auto LocPosActor0 = 5681111;
//    static constexpr auto LocPosActor1 = 5681116;
//    static constexpr auto LocPosActor2 = 5839603;
//    static constexpr auto Poprange0 = 5684830;

  public:
    GaiUse612() : Sapphire::ScriptAPI::EventScript( 65960 ){}; 
    ~GaiUse612() = default; 

  //////////////////////////////////////////////////////////////////////
  // Event Handlers
  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
    auto& eventMgr = Common::Service< World::Manager::EventMgr >::ref();
    auto actor = eventMgr.mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player );
        break;
      }
      case 1:
      {
        Scene00002( player );
        break;
      }
      case 255:
      {
        Scene00006( player );
        break;
      }
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

    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 1 );
    };

    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };

    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
        }
      }
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 10, NONE, callback );
  }

};

EXPOSE_SCRIPT( GaiUse612 );
