// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse219 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse219() : Sapphire::ScriptAPI::EventScript( 66899 ){}; 
  ~GaiUse219() = default; 

  //SEQ_0, 3 entries
  //SEQ_255, 4 entries

  //ACTOR0 = 1008696
  //ACTOR1 = 1008694
  //ACTOR2 = 1008695
  //ACTOR3 = 1008579
  //BGMNOTHING = 1
  //CUTSCENEN01 = 473
  //CUTSCENEN02 = 474
  //EVENTACTIONSEARCH = 1

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1008696 || actorId == 1008696 ) // ACTOR0 = YUGIRI
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008694 || actorId == 1008694 ) // ACTOR1 = UNDERGROUNDA01362
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=UNDERGROUNDA01362
        }
        if( actor == 1008695 || actorId == 1008695 ) // ACTOR2 = UNDERGROUNDB01362
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=UNDERGROUNDB01362
        }
        break;
      }
      case 255:
      {
        if( actor == 1008579 || actorId == 1008579 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(CutScene), id=unknown
          // +Callback Scene00005: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1008696 || actorId == 1008696 ) // ACTOR0 = YUGIRI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1008694 || actorId == 1008694 ) // ACTOR1 = UNDERGROUNDA01362
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=UNDERGROUNDA01362
        }
        if( actor == 1008695 || actorId == 1008695 ) // ACTOR2 = UNDERGROUNDB01362
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=UNDERGROUNDB01362
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse219:66899 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling Scene00002: Normal(Talk, TargetCanMove), id=UNDERGROUNDA01362" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling Scene00003: Normal(Talk, TargetCanMove), id=UNDERGROUNDB01362" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling Scene00004: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00005( player );
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling [BranchTrue]Scene00005: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 5, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling Scene00007: Normal(Talk, TargetCanMove), id=UNDERGROUNDA01362" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse219:66899 calling Scene00008: Normal(Talk, TargetCanMove), id=UNDERGROUNDB01362" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse219 );
