// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna608 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna608() : Sapphire::ScriptAPI::EventScript( 67193 ){}; 
  ~HeaVna608() = default; 

  //SEQ_0, 3 entries
  //SEQ_1, 3 entries
  //SEQ_2, 2 entries
  //SEQ_255, 3 entries

  //ACTIONTIMELINEEVENTSIGH = 4229
  //ACTIONTIMELINEEVENTTALKDEMIHUMAN = 949
  //ACTOR0 = 1012097
  //ACTOR1 = 1012409
  //ACTOR2 = 1012410
  //ACTOR3 = 1012416
  //ACTOR4 = 1012418
  //ACTOR5 = 1012417
  //EOBJECT0 = 2005422
  //QSTACTOR0 = 5863807
  //QSTACTOR1 = 5863813
  //QSTACTOR2 = 5860087
  //QUESTBATTLE0 = 112
  //TERRITORYTYPE0 = 485

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012097 || actorId == 1012097 ) // ACTOR0 = SLOWFIX
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLOWFIX
        }
        if( actor == 1012409 || actorId == 1012409 ) // ACTOR1 = ALPHINAUD
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012410 || actorId == 1012410 ) // ACTOR2 = YSHTOLA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        break;
      }
      case 1:
      {
        if( actor == 1012416 || actorId == 1012416 ) // ACTOR3 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(QuestBattle, YesNo), id=unknown
          }
        }
        if( actor == 2005422 || actorId == 2005422 ) // EOBJECT0 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1012097 || actorId == 1012097 ) // ACTOR0 = SLOWFIX
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=SLOWFIX
        }
        break;
      }
      case 2:
      {
        if( actor == 1012418 || actorId == 1012418 ) // ACTOR4 = YSHTOLA
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA
          }
        }
        if( actor == 1012417 || actorId == 1012417 ) // ACTOR5 = ALPHINAUD
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        break;
      }
      case 255:
      {
        if( actor == 1012097 || actorId == 1012097 ) // ACTOR0 = SLOWFIX
        {
          Scene00009( player ); // Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLOWFIX
        }
        if( actor == 1012409 || actorId == 1012409 ) // ACTOR1 = ALPHINAUD
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1012410 || actorId == 1012410 ) // ACTOR2 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
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

  void onEnterTerritory( Sapphire::Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2 ) override
  {
    onProgress( player, param1, param2, 4, 0 );
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
      player.updateQuest( getId(), 255 );
    }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna608:67193 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=SLOWFIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00002: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00003: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00004: Normal(QuestBattle, YesNo), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.setQuestUI8AL( getId(), 1 );
        checkProgressSeq1( player );
      }
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00005: Normal(None), id=unknown" );
    checkProgressSeq1( player );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00006: Normal(Talk, TargetCanMove), id=SLOWFIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00007: Normal(Talk, NpcDespawn, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00008: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00009: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=SLOWFIX" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00010: Normal(Talk, TargetCanMove), id=ALPHINAUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna608:67193 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna608 );
