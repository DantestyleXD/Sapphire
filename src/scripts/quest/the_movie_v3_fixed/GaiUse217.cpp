// FFXIVTheMovie.ParserV3
//fix: add code to enter instance, skip dungeon, avoid black screen after completion
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse217 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse217() : Sapphire::ScriptAPI::EventScript( 66897 ){}; 
  ~GaiUse217() = default; 

  //SEQ_0, 6 entries
  //SEQ_1, 7 entries
  //SEQ_255, 8 entries

  //ACTOR0 = 1008693
  //ACTOR1 = 1008891
  //ACTOR10 = 1001029
  //ACTOR11 = 1008676
  //ACTOR12 = 1008677
  //ACTOR13 = 1008678
  //ACTOR14 = 1008679
  //ACTOR2 = 1008892
  //ACTOR3 = 1008893
  //ACTOR4 = 1008894
  //ACTOR5 = 1008895
  //ACTOR6 = 5010000
  //ACTOR7 = 1005409
  //ACTOR8 = 1002694
  //ACTOR9 = 1008691
  //BGMNOTHING = 1
  //CUTSCENEN01 = 471
  //CUTSCENEN02 = 472
  //EVENTACTIONSEARCH = 1
  //INSTANCEDUNGEON0 = 20017
  //LOCACTOR0 = 4635444
  //LOCACTOR1 = 4635445
  //LOCACTOR2 = 4635446
  //LOCACTOR3 = 4635447
  //LOCACTOR4 = 4635448
  //LOCACTOR5 = 4629182
  //POPRANGE0 = 4633262
  //POPRANGE1 = 4628787
  //POPRANGE2 = 4635171
  //TERRITORYTYPE0 = 198
  //UNLOCKADDNEWCONTENTTOCF = 3702
  //UNLOCKDUNGEONLEVIATHANHARD = 182

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        if( actor == 1008693 || actorId == 1008693 ) // ACTOR0 = EYNZAHRSLAFYRSYN
        {
          Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
          // +Callback Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=EYNZAHRSLAFYRSYN
        }
        if( actor == 1008891 || actorId == 1008891 ) // ACTOR1 = MERLWYB
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MERLWYB
        }
        if( actor == 1008892 || actorId == 1008892 ) // ACTOR2 = MINFILIA
        {
          Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1008893 || actorId == 1008893 ) // ACTOR3 = THANCRED
        {
          Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1008894 || actorId == 1008894 ) // ACTOR4 = YSHTOLA
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1008895 || actorId == 1008895 ) // ACTOR5 = YUGIRI
        {
          Scene00006( player ); // Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        break;
      }
      case 1:
      {
        if( actor == 1008693 || actorId == 1008693 ) // ACTOR0 = EYNZAHRSLAFYRSYN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
        }
        if( actor == 1008891 || actorId == 1008891 ) // ACTOR1 = MERLWYB
        {
          Scene00008( player ); // Scene00008: Normal(Talk, TargetCanMove), id=MERLWYB
        }
        if( actor == 1008892 || actorId == 1008892 ) // ACTOR2 = MINFILIA
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1008893 || actorId == 1008893 ) // ACTOR3 = THANCRED
        {
          Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1008894 || actorId == 1008894 ) // ACTOR4 = YSHTOLA
        {
          Scene00011( player ); // Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1008895 || actorId == 1008895 ) // ACTOR5 = YUGIRI
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI
        }
        if( actor == 1005409 || actorId == 1005409 ) // ACTOR7 = STYRNLONA
        {
          Scene00013( player ); // Scene00013: Normal(Talk, TargetCanMove), id=STYRNLONA
        }
        break;
      }
      case 255:
      {
        if( actor == 1002694 || actorId == 1002694 ) // ACTOR8 = unknown
        {
          Scene00014( player ); // Scene00014: Normal(CutScene), id=unknown
          // +Callback Scene00015: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1008691 || actorId == 1008691 ) // ACTOR9 = EYNZAHRSLAFYRSYN
        {
          Scene00016( player ); // Scene00016: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN
        }
        if( actor == 1001029 || actorId == 1001029 ) // ACTOR10 = ZANTHAEL
        {
          Scene00017( player ); // Scene00017: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL
        }
        if( actor == 1008676 || actorId == 1008676 ) // ACTOR11 = MINFILIA
        {
          Scene00018( player ); // Scene00018: Normal(Talk, TargetCanMove), id=MINFILIA
        }
        if( actor == 1008677 || actorId == 1008677 ) // ACTOR12 = THANCRED
        {
          Scene00019( player ); // Scene00019: Normal(Talk, TargetCanMove), id=THANCRED
        }
        if( actor == 1008678 || actorId == 1008678 ) // ACTOR13 = YSHTOLA
        {
          Scene00020( player ); // Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA
        }
        if( actor == 1008679 || actorId == 1008679 ) // ACTOR14 = YUGIR
        {
          Scene00021( player ); // Scene00021: Normal(Talk, TargetCanMove), id=YUGIR
        }
        if( actor == 1005409 || actorId == 1005409 ) // ACTOR7 = STYRNLONA
        {
          Scene00022( player ); // Scene00022: Normal(Talk, TargetCanMove), id=STYRNLONA
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse217:66897 calling [BranchTrue]Scene00001: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00002: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00003: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00004: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00005: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00006: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00007: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00008: Normal(Talk, TargetCanMove), id=MERLWYB" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 8, NONE, callback );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00009: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00010: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00011: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 11, NONE, callback );
  }

  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00012: Normal(Talk, TargetCanMove), id=YUGIRI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }

  void Scene00013( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00013: Normal(Talk, TargetCanMove), id=STYRNLONA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 13, NONE, callback );
  }

  void Scene00014( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00014: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00015( player );
    };
    player.playScene( getId(), 14, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00015( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling [BranchTrue]Scene00015: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
        {
          player.finishQuest( getId() );
          player.eventFinish( getId(), 1 );
          player.exitInstance();
        }
      }
    };
    player.playScene( getId(), 15, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00016( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00016: Normal(Talk, TargetCanMove), id=EYNZAHRSLAFYRSYN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 16, NONE, callback );
  }

  void Scene00017( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00017: Normal(Talk, YesNo, TargetCanMove), id=ZANTHAEL" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        player.eventFinish( getId(), 1 );
        player.enterPredefinedPrivateInstance( 198 );
      }
    };
    player.playScene( getId(), 17, NONE, callback );
  }

  void Scene00018( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00018: Normal(Talk, TargetCanMove), id=MINFILIA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 18, NONE, callback );
  }

  void Scene00019( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00019: Normal(Talk, TargetCanMove), id=THANCRED" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 19, NONE, callback );
  }

  void Scene00020( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00020: Normal(Talk, TargetCanMove), id=YSHTOLA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 20, NONE, callback );
  }

  void Scene00021( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00021: Normal(Talk, TargetCanMove), id=YUGIR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 21, NONE, callback );
  }

  void Scene00022( Entity::Player& player )
  {
    player.sendDebug( "GaiUse217:66897 calling Scene00022: Normal(Talk, TargetCanMove), id=STYRNLONA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 22, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse217 );
