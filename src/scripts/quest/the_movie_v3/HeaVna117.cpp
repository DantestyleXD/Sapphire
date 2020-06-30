// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna117 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna117() : Sapphire::ScriptAPI::EventScript( 67132 ){}; 
  ~HeaVna117() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 7 entries
  //SEQ_2, 2 entries
  //SEQ_255, 2 entries

  //ACTIONTIMELINEEVENTBASESORRY = 819
  //ACTIONTIMELINEEVENTSIGH = 4229
  //ACTIONTIMELINEEVENTSPECIALJOY = 1059
  //ACTIONTIMELINEFACIALCRY = 612
  //ACTIONTIMELINEFACIALWORRY = 620
  //ACTIONTIMELINETALKJOKE = 4220
  //ACTOR0 = 1012368
  //ACTOR1 = 1012369
  //ACTOR2 = 1012370
  //ACTOR3 = 1013091
  //ACTOR4 = 1013092
  //ACTOR5 = 1012371
  //ACTOR6 = 1011952
  //ACTOR7 = 1012375
  //ACTOR8 = 1012329
  //ACTOR9 = 1012327
  //LOCACTOR0 = 1013876
  //LOCACTOR1 = 1007699
  //LOCACTOR2 = 5858152
  //LOCACTOR3 = 5853131

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1012368 || actorId == 1012368 ) // ACTOR0 = EMMANELLAIN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012369 || actorId == 1012369 ) // ACTOR1 = HAURCHEFANT
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012370 || actorId == 1012370 ) // ACTOR2 = unknown
        {
          Scene00003( player ); // Scene00003: Normal(None), id=unknown
        }
        if( actor == 1013091 || actorId == 1013091 ) // ACTOR3 = unknown
        {
          Scene00004( player ); // Scene00004: Normal(None), id=unknown
        }
        if( actor == 1013092 || actorId == 1013092 ) // ACTOR4 = unknown
        {
          Scene00005( player ); // Scene00005: Normal(None), id=unknown
        }
        if( actor == 1012371 || actorId == 1012371 ) // ACTOR5 = HONOROIT
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        break;
      }
      case 1:
      {
        if( actor == 1011952 || actorId == 1011952 ) // ACTOR6 = LANIAITTE
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00007( player ); // Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=LANIAITTE
          }
        }
        if( actor == 1012371 || actorId == 1012371 ) // ACTOR5 = HONOROIT
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=HONOROIT
        }
        if( actor == 1012368 || actorId == 1012368 ) // ACTOR0 = EMMANELLAIN
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012369 || actorId == 1012369 ) // ACTOR1 = HAURCHEFANT
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=HAURCHEFANT
        }
        if( actor == 1012370 || actorId == 1012370 ) // ACTOR2 = unknown
        {
          Scene00011( player ); // Scene00011: Normal(None), id=unknown
        }
        if( actor == 1013091 || actorId == 1013091 ) // ACTOR3 = unknown
        {
          Scene00012( player ); // Scene00012: Normal(None), id=unknown
        }
        if( actor == 1013092 || actorId == 1013092 ) // ACTOR4 = unknown
        {
          Scene00013( player ); // Scene00013: Normal(None), id=unknown
        }
        break;
      }
      case 2:
      {
        if( actor == 1012375 || actorId == 1012375 ) // ACTOR7 = HAURCHEFANT
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00014( player ); // Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=HAURCHEFANT
          }
        }
        if( actor == 1011952 || actorId == 1011952 ) // ACTOR6 = LANIAITTE
        {
          Scene00015( player ); // Scene00015: Normal(Talk, TargetCanMove), id=LANIAITTE
        }
        break;
      }
      case 255:
      {
        if( actor == 1012329 || actorId == 1012329 ) // ACTOR8 = EMMANELLAIN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=EMMANELLAIN
        }
        if( actor == 1012327 || actorId == 1012327 ) // ACTOR9 = HONOROIT
        {
          Scene00017( player ); // Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT
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
    player.sendDebug( "HeaVna117:67132 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna117:67132 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00002: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00003: Normal(None), id=unknown" );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00004: Normal(None), id=unknown" );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00005: Normal(None), id=unknown" );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00006: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00007: Normal(Talk, FadeIn, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00008: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00009: Normal(Talk, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00010: Normal(Talk, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00011: Normal(None), id=unknown" );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00012: Normal(None), id=unknown" );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00013: Normal(None), id=unknown" );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00014: Normal(Talk, NpcDespawn, TargetCanMove), id=HAURCHEFANT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 14, NONE, callback );
  }

  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00015: Normal(Talk, TargetCanMove), id=LANIAITTE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 15, NONE, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00016: Normal(Talk, FadeIn, QuestReward, QuestComplete, TargetCanMove), id=EMMANELLAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 16, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "HeaVna117:67132 calling Scene00017: Normal(Talk, TargetCanMove), id=HONOROIT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 17, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna117 );
