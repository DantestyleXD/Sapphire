// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class HeaVna334 : public Sapphire::ScriptAPI::EventScript
{
public:
  HeaVna334() : Sapphire::ScriptAPI::EventScript( 67171 ){}; 
  ~HeaVna334() = default; 

  //SEQ_0, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1012746
  //ACTOR1 = 1013172
  //ACTOR2 = 1014110
  //CUTSCENEN01 = 843
  //CUTSCENEN02 = 844
  //CUTSCENEN03 = 845
  //LOCACTOR0 = 5860776
  //LOCACTOR1 = 5899672

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ESTINIEN
        break;
      }
      case 255:
      {
        if( actor == 1013172 || actorId == 1013172 ) // ACTOR1 = ICEHEART
        {
          Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=ICEHEART
          // +Callback Scene00003: Normal(CutScene), id=unknown
          // +Callback Scene00004: Normal(FadeIn, QuestReward, QuestComplete), id=unknown
        }
        if( actor == 1014110 || actorId == 1014110 ) // ACTOR2 = ESTINIEN
        {
          Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN
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
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "HeaVna334:67171 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "HeaVna334:67171 calling [BranchTrue]Scene00001: Normal(Talk, NpcDespawn, QuestAccept, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "HeaVna334:67171 calling Scene00002: Normal(Talk, TargetCanMove), id=ICEHEART" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00003( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }
  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "HeaVna334:67171 calling [BranchTrue]Scene00003: Normal(CutScene), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      Scene00004( player );
    };
    player.playScene( getId(), 3, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }
  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "HeaVna334:67171 calling [BranchChain]Scene00004: Normal(FadeIn, QuestReward, QuestComplete), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 4, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "HeaVna334:67171 calling Scene00005: Normal(Talk, TargetCanMove), id=ESTINIEN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 5, NONE, callback );
  }
};

EXPOSE_SCRIPT( HeaVna334 );
