// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubWil083 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubWil083() : Sapphire::ScriptAPI::EventScript( 65867 ){}; 
  ~SubWil083() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 5 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1001605
  //ENEMY0 = 4142933
  //ENEMY1 = 352
  //ENEMY2 = 353
  //EOBJECT0 = 2001740
  //EVENTRANGE0 = 4143296

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
      case 1:
      {
        if( actor == 4143296 || actorId == 4143296 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4142933 || actorId == 4142933 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 352 || actorId == 352 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 353 || actorId == 353 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        if( actor == 2001740 || actorId == 2001740 ) // EOBJECT0 = unknown
        {
          Scene00002( player ); // Scene00002: Normal(None), id=unknown
        }
        break;
      }
      case 255:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown
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
    if( player.getQuestUI8BL( getId() ) == 1 )
    {
      player.setQuestUI8BL( getId(), 0 );
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubWil083:65867 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=unknown" );
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
    player.sendDebug( "SubWil083:65867 calling Scene00001: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubWil083:65867 calling Scene00002: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubWil083:65867 calling Scene00003: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 3, NONE, callback );
  }
};

EXPOSE_SCRIPT( SubWil083 );