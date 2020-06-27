// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst159 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst159() : Sapphire::ScriptAPI::EventScript( 66961 ){}; 
  ~SubFst159() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1000375
  //ACTOR1 = 1007792
  //ACTOR2 = 1000153
  //ACTOR3 = 1007793
  //ACTOR4 = 1007794
  //ACTOR5 = 1007795
  //ACTOR6 = 1007969
  //ACTOR7 = 1007970
  //ACTOR8 = 1007971
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2001249
  //LOCACTOR0 = 1007990
  //LOCACTOR1 = 1007991
  //LOCACTOR2 = 1007992
  //LOCACTOR3 = 1000153
  //LOCBGM = 88
  //LOCBGM2 = 87
  //LOCFACE0 = 604
  //LOCFACE1 = 605
  //LOCFACE2 = 614
  //LOCMOTION1 = 571
  //LOCMOTION2 = 572
  //LOCPOSACTOR0 = 4666289
  //LOCPOSACTOR1 = 4666740
  //QUEST0 = 65741

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ERAL
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=YEADYTHE
        break;
      }
      //seq 2 event item ITEM0 = UI8BH max stack 1
      case 2:
      {
        if( actor == 1000153 || actorId == 1000153 ) // ACTOR2 = BEATINE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=BEATINE
          }
        }
        if( actor == 1007792 || actorId == 1007792 ) // ACTOR1 = YEADYTHE
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=YEADYTHE
        }
        break;
      }
      //seq 3 event item ITEM0 = UI8BH max stack 1
      case 3:
      {
        if( actor == 1007793 || actorId == 1007793 ) // ACTOR3 = BOY01425
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=BOY01425
          }
          else
          {
            Scene00007( player ); // Scene00007: Normal(None), id=unknown
          }
        }
        if( actor == 1007794 || actorId == 1007794 ) // ACTOR4 = GIRL01425
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00008( player ); // Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=GIRL01425
          }
          else
          {
            Scene00010( player ); // Scene00010: Normal(None), id=unknown
          }
        }
        if( actor == 1007795 || actorId == 1007795 ) // ACTOR5 = BOY201425
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00011( player ); // Scene00011: NpcTrade(Talk), id=unknown
            // +Callback Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=BOY201425
          }
        }
        if( actor == 1007792 || actorId == 1007792 ) // ACTOR1 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        if( actor == 1007792 || actorId == 1007792 ) // ACTOR1 = YEADYTHE
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=YEADYTHE
          // +Callback Scene00015: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YEADYTHE
        }
        if( actor == 1007969 || actorId == 1007969 ) // ACTOR6 = unknown
        {
          Scene00016( player ); // Scene00016: Normal(None), id=unknown
        }
        if( actor == 1007970 || actorId == 1007970 ) // ACTOR7 = unknown
        {
          Scene00017( player ); // Scene00017: Normal(None), id=unknown
        }
        if( actor == 1007971 || actorId == 1007971 ) // ACTOR8 = unknown
        {
          Scene00018( player ); // Scene00018: Normal(None), id=unknown
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
    player.updateQuest( getId(), 2 );
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 3 );
      player.setQuestUI8BH( getId(), 1 );
    }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=ERAL" );
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
    player.sendDebug( "SubFst159:66961 calling [BranchTrue]Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00002: Normal(Talk, TargetCanMove), id=YEADYTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00003: Normal(Talk, TargetCanMove), id=BEATINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00004: Normal(Talk, TargetCanMove), id=YEADYTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00006( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling [BranchTrue]Scene00006: Normal(Talk, NpcDespawn, TargetCanMove), id=BOY01425" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling [BranchFalse]Scene00007: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00009( player );
      }
    };
    player.playScene( getId(), 8, NONE, callback );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling [BranchTrue]Scene00009: Normal(Talk, NpcDespawn, TargetCanMove), id=GIRL01425" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling [BranchFalse]Scene00010: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
    checkProgressSeq3( player );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00011: NpcTrade(Talk), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00012( player );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling [BranchTrue]Scene00012: Normal(Talk, NpcDespawn, TargetCanMove), id=BOY201425" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00014: Normal(Talk, TargetCanMove), id=YEADYTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling [BranchTrue]Scene00015: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=YEADYTHE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00016: Normal(None), id=unknown" );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00017: Normal(None), id=unknown" );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubFst159:66961 calling Scene00018: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubFst159 );
