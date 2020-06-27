// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class GaiUsa002 : public Sapphire::ScriptAPI::EventScript
{
public:
  GaiUsa002() : Sapphire::ScriptAPI::EventScript( 66244 ){}; 
  ~GaiUsa002() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 1 entries
  //SEQ_2, 1 entries
  //SEQ_3, 6 entries
  //SEQ_4, 1 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000168
  //ACTOR1 = 1000257
  //ACTOR2 = 1000766
  //ACTOR3 = 1006188
  //ENEMY0 = 4269923
  //ENEMY1 = 4269925
  //ENEMY2 = 4269926
  //EOBJECT0 = 2002610
  //EOBJECT1 = 2002611
  //EOBJECT2 = 2002612
  //EVENTACTIONSEARCH = 1
  //EVENTACTIONWAITINGSHOR = 11
  //ITEM0 = 2000826
  //LOCACTOR0 = 1002275
  //LOCACTOR1 = 1002276
  //SEQ0ACTOR0LQ = 90

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown
        // +Callback Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=VORSAILE
        break;
      }
      case 1:
      {
        Scene00002( player ); // Scene00002: Normal(Talk, TargetCanMove), id=MITAINIE
        break;
      }
      case 2:
      {
        Scene00003( player ); // Scene00003: Normal(Talk, TargetCanMove), id=ROSA
        break;
      }
      case 3:
      {
        if( actor == 2002610 || actorId == 2002610 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00005: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4269923 || actorId == 4269923 ) // ENEMY0 = unknown
        {
          // empty entry
        }
        if( actor == 2002611 || actorId == 2002611 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 1 )
          {
            Scene00006( player ); // Scene00006: Normal(None), id=unknown
            // +Callback Scene00007: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4269925 || actorId == 4269925 ) // ENEMY1 = unknown
        {
          // empty entry
        }
        if( actor == 2002612 || actorId == 2002612 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00008( player ); // Scene00008: Normal(None), id=unknown
            // +Callback Scene00009: Normal(Message, PopBNpc), id=unknown
          }
        }
        if( actor == 4269926 || actorId == 4269926 ) // ENEMY2 = unknown
        {
          // empty entry
        }
        break;
      }
      //seq 4 event item ITEM0 = UI8BH max stack 1
      case 4:
      {
        Scene00010( player ); // Scene00010: Normal(Talk, TargetCanMove), id=ROSA
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      case 255:
      {
        Scene00011( player ); // Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown
        // +Callback Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AMELAIN
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
    player.updateQuest( getId(), 3 );
  }
  void checkProgressSeq3( Entity::Player& player )
  {
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 1 )
        if( player.getQuestUI8BL( getId() ) == 1 )
        {
          player.setQuestUI8AL( getId(), 0 );
          player.setQuestUI8BH( getId(), 0 );
          player.setQuestUI8BL( getId(), 0 );
          player.updateQuest( getId(), 4 );
        }
  }
  void checkProgressSeq4( Entity::Player& player )
  {
    player.updateQuest( getId(), 255 );
    player.setQuestUI8BH( getId(), 1 );
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00000: Normal(QuestOffer, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00090( player );
      }
    };
    player.playScene( getId(), 0, NONE, callback );
  }
  void Scene00090( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling [BranchTrue]Scene00090: Normal(Talk, FadeIn, QuestAccept, TargetCanMove), id=VORSAILE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq0( player );
    };
    player.playScene( getId(), 90, FADE_OUT | CONDITION_CUTSCENE | HIDE_UI, callback );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00002: Normal(Talk, TargetCanMove), id=MITAINIE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq1( player );
    };
    player.playScene( getId(), 2, NONE, callback );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00003: Normal(Talk, TargetCanMove), id=ROSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq2( player );
    };
    player.playScene( getId(), 3, NONE, callback );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00004: Normal(None), id=unknown" );
    Scene00005( player );
  }
  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling [BranchTrue]Scene00005: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8AL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 5, NONE, callback );
  }

  void Scene00006( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00006: Normal(None), id=unknown" );
    Scene00007( player );
  }
  void Scene00007( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling [BranchTrue]Scene00007: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BH( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 7, NONE, callback );
  }

  void Scene00008( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00008: Normal(None), id=unknown" );
    Scene00009( player );
  }
  void Scene00009( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling [BranchTrue]Scene00009: Normal(Message, PopBNpc), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      player.setQuestUI8BL( getId(), 1 );
      checkProgressSeq3( player );
    };
    player.playScene( getId(), 9, NONE, callback );
  }

  void Scene00010( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00010: Normal(Talk, TargetCanMove), id=ROSA" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      checkProgressSeq4( player );
    };
    player.playScene( getId(), 10, NONE, callback );
  }

  void Scene00011( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling Scene00011: NpcTrade(Talk, TargetCanMove), id=unknown" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00012( player );
      }
    };
    player.playScene( getId(), 11, NONE, callback );
  }
  void Scene00012( Entity::Player& player )
  {
    player.sendDebug( "GaiUsa002:66244 calling [BranchTrue]Scene00012: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=AMELAIN" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        if( player.giveQuestRewards( getId(), result.param3 ) )
          player.finishQuest( getId() );
      }
    };
    player.playScene( getId(), 12, NONE, callback );
  }
};

EXPOSE_SCRIPT( GaiUsa002 );
