// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil087 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil087() : Sapphire::ScriptAPI::EventScript( 65871 ){}; 
  ~SubWil087() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 3 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1002071
  //ENEMY0 = 12
  //ENEMY1 = 382
  //ENEMY2 = 389
  //ITEM0 = 2000382
  //ITEM1 = 2000383
  //ITEM2 = 2000384

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 2
      //seq 1 event item ITEM1 = UI8CL max stack 2
      //seq 1 event item ITEM2 = UI8DH max stack 2
      case 1:
      {
        if( actor == 12 || actorId == 12 ) // ENEMY0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 382 || actorId == 382 ) // ENEMY1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        if( actor == 389 || actorId == 389 ) // ENEMY2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 2 )
          {
            player.setQuestUI8BL( getId(), player.getQuestUI8BL( getId() ) + 1 );
            checkProgressSeq1( player );
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 2
      //seq 255 event item ITEM1 = UI8BL max stack 2
      //seq 255 event item ITEM2 = UI8CH max stack 2
      case 255:
      {
        Scene00001( player ); // Scene00001: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
        // +Callback Scene00003: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8BH( getId() ) == 2 )
        if( player.getQuestUI8BL( getId() ) == 2 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.setQuestUI8CH( getId(), 0 );
          player.setQuestUI8CL( getId(), 0 );
          player.setQuestUI8DH( getId(), 0 );
          player.updateQuest( getId(), 255 );
          player.setQuestUI8BH( getId(), 2 );
          player.setQuestUI8BL( getId(), 2 );
          player.setQuestUI8CH( getId(), 2 );
        }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil087:65871 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        checkProgressSeq0( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }

  void Scene00001( Entity::Player& player )
  {
    player.sendDebug( "SubWil087:65871 calling Scene00001: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00002( player );
      }
    };
    player.playScene( getId(), 1, NONE, callback );
  }
  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil087:65871 calling [BranchTrue]Scene00002: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubWil087:65871 calling [BranchChain]Scene00003: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubWil087 );
