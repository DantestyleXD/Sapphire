// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUse103 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUse103() : Sapphire::ScriptAPI::EventScript( 66713 ){}; 
  ~GaiUse103() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 2 entries
  //SEQ_3, 1 entries
  //SEQ_4, 5 entries
  //SEQ_5, 1 entries
  //SEQ_255, 2 entries

  //ACTOR0 = 1006355
  //ACTOR1 = 1006273
  //ACTOR2 = 1006309
  //ACTOR3 = 1006306
  //ACTOR4 = 1006305
  //ACTOR5 = 1007738
  //ACTOR6 = 1007752
  //ACTOR7 = 1007739
  //ENEMY0 = 4500980
  //EOBJECT0 = 2002841
  //EVENTRANGE0 = 4500971
  //LOCACTOR0 = 1007768
  //LOCFACE0 = 619
  //LOCFACE1 = 605
  //LOCPOSACTOR0 = 4520606
  //LOCPOSACTOR1 = 4520834

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILIUD
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=GEGERUJU
        break;
      }
      case 2:
      {
        if( actor == 1006309 || actorId == 1006309 ) // ACTOR2 = JUNGHBHAR
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=JUNGHBHAR
          }
        }
        if( actor == 1006306 || actorId == 1006306 ) // ACTOR3 = BYRGLAENT
        {
          if( player.getQuestUI8AL( getId() ) != 2 )
          {
            Scene00004( player ); // Scene00004: Normal(Talk, TargetCanMove), id=BYRGLAENT
          }
        }
        break;
      }
      case 3:
      {
        Scene00005( player ); // Scene00005: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
        break;
      }
      case 4:
      {
        if( actor == 4500971 || actorId == 4500971 ) // EVENTRANGE0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4500980 || actorId == 4500980 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 1007738 || actorId == 1007738 ) // ACTOR5 = FLHAMINN
        {
          Scene00007( player ); // Scene00007: Normal(Talk, TargetCanMove), id=FLHAMINN
        }
        if( actor == 2002841 || actorId == 2002841 ) // EOBJECT0 = unknown
        {
          Scene00008( player ); // Scene00008: Normal(None), id=unknown
        }
        if( actor == 1006305 || actorId == 1006305 ) // ACTOR4 = SHAMANILOHMANI
        {
          Scene00009( player ); // Scene00009: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI
        }
        break;
      }
      case 5:
      {
        Scene00010( player ); // Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=FLHAMINN
        break;
      }
      case 255:
      {
        if( actor == 1007752 || actorId == 1007752 ) // ACTOR6 = ALPHINAUD
        {
          Scene00011( player ); // Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD
        }
        if( actor == 1007739 || actorId == 1007739 ) // ACTOR7 = FLHAMINN
        {
          Scene00012( player ); // Scene00012: Normal(Talk, TargetCanMove), id=FLHAMINN
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
    if( player.getQuestUI8AL( getId() ) == 2 )
      if( player.getQuestUI8AL( getId() ) == 2 )
      {
        player.setQuestUI8AL( getId(), 0 );
        player.setQuestUI8AL( getId(), 0 );
        player.updateQuest( getId(), 3 );
      }
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    player.updateQuest( getId(), 4 );
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
    {
      player.setQuestUI8AL( getId(), 0 );
      player.updateQuest( getId(), 5 );
    }
  }
  void checkProgressSeq5( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
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
    player.sendDebug( "GaiUse103:66713 calling [BranchTrue]Scene00001: Normal(Talk, QuestAccept, TargetCanMove), id=ILIUD" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 1, NONE, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00002: Normal(Talk, TargetCanMove), id=GEGERUJU" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00003: Normal(Talk, TargetCanMove), id=JUNGHBHAR" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00004: Normal(Talk, TargetCanMove), id=BYRGLAENT" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), player.getQuestUI8AL( getId() ) + 1 );
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 4, NONE, callback );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00005: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00006: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 6, NONE, callback );
  }

  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00007: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00008: Normal(None), id=unknown" );
    checkProgressSeq4( player );
  }

  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00009: Normal(Talk, TargetCanMove), id=SHAMANILOHMANI" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00010: Normal(Talk, FadeIn, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq5( player );
    };
    player.playScene( getId(), 10, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUse103:66713 calling Scene00011: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=ALPHINAUD" );
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
    player.sendDebug( "GaiUse103:66713 calling Scene00012: Normal(Talk, TargetCanMove), id=FLHAMINN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUse103 );
