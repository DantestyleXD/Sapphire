// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil159 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil159() : Sapphire::ScriptAPI::EventScript( 66963 ){}; 
  ~SubWil159() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_2, 4 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1007799
  //ACTOR1 = 1007800
  //ACTOR2 = 1001697
  //ACTOR3 = 1007801
  //ACTOR4 = 1007798
  //EVENTACTIONSEARCH = 1
  //LOCACTION0 = 573
  //LOCACTION1 = 574
  //LOCACTOR0 = 1007993
  //LOCBGM1 = 88
  //LOCBGM2 = 82
  //LOCFACE0 = 605
  //LOCFACE1 = 612
  //LOCFACE2 = 615
  //LOCFACE3 = 606
  //LOCPOSACTOR0 = 4672004
  //LOCPOSACTOR1 = 4672622
  //LOCPOSACTOR2 = 4672825

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=PMOLMINN
        // +Callback Scene00001: Normal(QuestAccept), id=unknown
        break;
      }
      case 1:
      {
        if( actor == 1007800 || actorId == 1007800 ) // ACTOR1 = WOMENA01427
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=WOMENA01427
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=WOMENA01427
          }
        }
        if( actor == 1001697 || actorId == 1001697 ) // ACTOR2 = SOSOTTA
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=SOSOTTA
            // +Callback Scene00005: Normal(Talk, TargetCanMove), id=SOSOTTA
          }
        }
        if( actor == 1007801 || actorId == 1007801 ) // ACTOR3 = WOMENB01427
        {
          if( player.getQuestUI8AL( getId() ) != 3 )
          {
            Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=WOMENB01427
            // +Callback Scene00007: Normal(Talk, TargetCanMove), id=WOMENB01427
          }
        }
        if( actor == 1007799 || actorId == 1007799 ) // ACTOR0 = PMOLMINN
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=PMOLMINN
        }
        break;
      }
      case 2:
      {
        if( actor == 1007798 || actorId == 1007798 ) // ACTOR4 = GUILLAUNAUX
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=GUILLAUNAUX
          }
        }
        if( actor == 1007799 || actorId == 1007799 ) // ACTOR0 = PMOLMINN
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=PMOLMINN
        }
        if( actor == 1007800 || actorId == 1007800 ) // ACTOR1 = WOMENA01427
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=WOMENA01427
        }
        if( actor == 1007801 || actorId == 1007801 ) // ACTOR3 = WOMENB01427
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=WOMENB01427
        }
        break;
      }
      case 255:
      {
        if( actor == 1007798 || actorId == 1007798 ) // ACTOR4 = GUILLAUNAUX
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=GUILLAUNAUX
          // +Callback Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=GUILLAUNAUX
          // +Callback Scene00015: Normal(Talk, TargetCanMove), id=GUILLAUNAUX
        }
        if( actor == 1007799 || actorId == 1007799 ) // ACTOR0 = PMOLMINN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=PMOLMINN
        }
        if( actor == 1007800 || actorId == 1007800 ) // ACTOR1 = WOMENA01427
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=WOMENA01427
        }
        if( actor == 1007801 || actorId == 1007801 ) // ACTOR3 = WOMENB01427
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=WOMENB01427
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
    if( player.getQuestUI8AL( getId() ) == 3 )
      if( player.getQuestUI8AL( getId() ) == 3 )
        if( player.getQuestUI8AL( getId() ) == 3 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8AL( getId(), 0 );
          player.updateQuest( getId(), 2 );
        }
  }
  void checkProgressSeq2( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00000: Normal(Talk, QuestOffer, TargetCanMove), id=PMOLMINN" );
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
    player.sendDebug( "SubWil159:66963 calling [BranchTrue]Scene00001: Normal(QuestAccept), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00002: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling [BranchTrue]Scene00003: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00004: Normal(Talk, TargetCanMove), id=SOSOTTA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling [BranchTrue]Scene00005: Normal(Talk, TargetCanMove), id=SOSOTTA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00006: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00007( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling [BranchTrue]Scene00007: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00008: Normal(Talk, TargetCanMove), id=PMOLMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00009: Normal(Talk, TargetCanMove), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00010: Normal(Talk, TargetCanMove), id=PMOLMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00011: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00012: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00013: Normal(Talk, TargetCanMove), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00014( player );
    };
    player.playScene( getId(), 13, NONE, callback );
  }
  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling [BranchTrue]Scene00014: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00015( player );
      }
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling [BranchChain]Scene00015: Normal(Talk, TargetCanMove), id=GUILLAUNAUX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( player.giveQuestRewards( getId(), result.param3 ) )
        player.finishQuest( getId() );
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00016: Normal(Talk, TargetCanMove), id=PMOLMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00017: Normal(Talk, TargetCanMove), id=WOMENA01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "SubWil159:66963 calling Scene00018: Normal(Talk, TargetCanMove), id=WOMENB01427" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil159 );
