// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsc503 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsc503() : Sapphire::ScriptAPI::EventScript( 66527 ){}; 
  ~GaiUsc503() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1006545
  //ACTOR1 = 1006546
  //ACTOR2 = 1006547
  //ACTOR3 = 1006548
  //ITEM0 = 2000759
  //ITEM1 = 2000760
  //ITEM2 = 2000761

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      //seq 0 event item ITEM0 = UI8BH max stack 1
      //seq 0 event item ITEM1 = UI8BL max stack ?
      //seq 0 event item ITEM2 = UI8CH max stack ?
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NAZYLDUZYL
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      //seq 1 event item ITEM1 = UI8CL max stack ?
      //seq 1 event item ITEM2 = UI8DH max stack ?
      case 1:
      {
        if( actor == 1006546 || actorId == 1006546 ) // ACTOR1 = NPCA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00002( player ); // Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00003: Normal(Talk, TargetCanMove), id=NPCA
          }
          else
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=NPCA
          }
        }
        if( actor == 1006547 || actorId == 1006547 ) // ACTOR2 = NPCB
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00006: Normal(Talk, TargetCanMove), id=NPCB
          }
          else
          {
            Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=NPCB
          }
        }
        if( actor == 1006548 || actorId == 1006548 ) // ACTOR3 = NPCC
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown
            // +Callback Scene00009: Normal(Talk, TargetCanMove), id=NPCC
          }
          else
          {
            Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=NPCC
          }
        }
        break;
      }
      case 255:
      {
        if( actor == 1006545 || actorId == 1006545 ) // ACTOR0 = NAZYLDUZYL
        {
          Scene00011( player ); // Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NAZYLDUZYL
        }
        if( actor == 1006546 || actorId == 1006546 ) // ACTOR1 = NPCA
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=NPCA
        }
        if( actor == 1006547 || actorId == 1006547 ) // ACTOR2 = NPCB
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=NPCB
        }
        if( actor == 1006548 || actorId == 1006548 ) // ACTOR3 = NPCC
        {
          Scene00014( player ); // Scene00014: Normal(Talk, TargetCanMove), id=NPCC
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
    player.setQuestUI8CH( getId(), 1 );
    player.setQuestUI8CL( getId(), 1 );
    player.setQuestUI8DH( getId(), 1 );
  }
  void checkProgressSeq1( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 255 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc503:66527 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=NAZYLDUZYL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00002: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00003( player );
      }
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling [BranchTrue]Scene00003: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling [BranchFalse]Scene00004: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc503:66527 calling [BranchTrue]Scene00006: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling [BranchFalse]Scene00007: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00008: NpcTrade(Talk, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUsc503:66527 calling [BranchTrue]Scene00009: Normal(Talk, TargetCanMove), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }
  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling [BranchFalse]Scene00010: Normal(Talk, TargetCanMove), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=NAZYLDUZYL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00012: Normal(Talk, TargetCanMove), id=NPCA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00013: Normal(Talk, TargetCanMove), id=NPCB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUsc503:66527 calling Scene00014: Normal(Talk, TargetCanMove), id=NPCC" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 14, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsc503 );
