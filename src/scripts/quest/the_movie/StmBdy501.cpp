// This is an automatically generated C++ script template
// Content needs to be added by hand to make it function
// In order for this script to be loaded, move it to the correct folder in <root>/scripts/

#include <Actor/Player.h>
#include "Manager/EventMgr.h"
#include <ScriptObject.h>
#include <Service.h>

// Quest Script: StmBdy501_03086
// Quest Name: Precious Reclamation
// Quest ID: 68622
// Start NPC: 1024791
// End NPC: 2009436

using namespace Sapphire;

class StmBdy501 : public Sapphire::ScriptAPI::EventScript
{
  private:
    // Basic quest information 
    // Quest vars / flags used
    // GetQuestBitFlag8
    // GetQuestUI8AL
    // GetQuestUI8BH

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
//    static constexpr auto Actor0 = 1024791;
//    static constexpr auto Actor1 = 1025346;
//    static constexpr auto Actor2 = 1006530;
//    static constexpr auto Actor3 = 1025287;
//    static constexpr auto BindActor01 = 7247540;
//    static constexpr auto BindActor02 = 7247541;
//    static constexpr auto BindActor03 = 7247543;
//    static constexpr auto BindActor04 = 7291188;
//    static constexpr auto BindActor05 = 4614989;
//    static constexpr auto BindActor06 = 4614991;
//    static constexpr auto Eobject0 = 2009436;
//    static constexpr auto Eventaction0 = 10;
//    static constexpr auto Item0 = 2002465;
//    static constexpr auto LocAction01 = 4308;
//    static constexpr auto LocAction02 = 665;
//    static constexpr auto LocActor01 = 1019544;
//    static constexpr auto LocActor02 = 1025188;
//    static constexpr auto LocActor03 = 1025189;
//    static constexpr auto LocActor04 = 1012448;
//    static constexpr auto LocActor05 = 1012449;
//    static constexpr auto LocActor06 = 1025190;
//    static constexpr auto LocActor07 = 1025191;
//    static constexpr auto LocActor08 = 1010807;
//    static constexpr auto LocActor09 = 1009836;
//    static constexpr auto LocActor10 = 1009837;
//    static constexpr auto LocActor100 = 1025012;
//    static constexpr auto LocActor101 = 1009815;
//    static constexpr auto LocActor102 = 1015119;
//    static constexpr auto LocActor11 = 1009838;
//    static constexpr auto LocActor12 = 1025363;
//    static constexpr auto LocBgm01 = 489;
//    static constexpr auto LocQuestCheck01 = 68562;
//    static constexpr auto LocQuestCheck02 = 65581;
//    static constexpr auto LocQuestCheck03 = 65636;
//    static constexpr auto LocSe01 = 111;

  public:
    StmBdy501() : Sapphire::ScriptAPI::EventScript( 68622 ){}; 
    ~StmBdy501() = default; 

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
        Scene00003( player );
        break;
      }
      case 2:
      {
        Scene00005( player );
        break;
      }
      case 255:
      {
        Scene00011( player );
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

    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };

    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 2 );
    };

    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00006( player );
    };

    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };

    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00008( player );
    };

    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00009( player );
    };

    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00010( player );
    };

    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.updateQuest( getId(), 255 );
    };

    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
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

    player.playScene( getId(), 11, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };

    player.playScene( getId(), 13, NONE, callback );
  }

};

EXPOSE_SCRIPT( StmBdy501 );
