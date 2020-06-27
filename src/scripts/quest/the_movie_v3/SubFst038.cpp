// FFXIVTheMovie.ParserV3
#include <Actor/Player.h>
#include <ScriptObject.h>
#include <Service.h>
#include "Manager/TerritoryMgr.h"
#include "Manager/EventMgr.h"

using namespace Sapphire;

class SubFst038 : public Sapphire::ScriptAPI::EventScript
{
public:
  SubFst038() : Sapphire::ScriptAPI::EventScript( 65711 ){}; 
  ~SubFst038() = default; 

  //SEQ_0, 1 entries
  //SEQ_1, 4 entries
  //SEQ_255, 1 entries

  //ACTOR0 = 1000449
  //ACTOR1 = 1000685
  //EOBJECT0 = 2000141
  //EOBJECT1 = 2000147
  //EOBJECT2 = 2000148
  //EOBJECT3 = 2000149
  //EVENTACTIONSEARCH = 1
  //ITEM0 = 2000141
  //ITEM1 = 2000146
  //ITEM2 = 2000147

private:
  void onProgress( Entity::Player& player, uint64_t actorId, uint32_t actor, uint32_t type, uint32_t param )
  {
    switch( player.getQuestSeq( getId() ) )
    {
      case 0:
      {
        Scene00000( player ); // Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=MONRANGUIN
        break;
      }
      //seq 1 event item ITEM0 = UI8CH max stack 1
      //seq 1 event item ITEM1 = UI8CL max stack 2
      //seq 1 event item ITEM2 = UI8DH max stack 1
      case 1:
      {
        if( actor == 2000141 || actorId == 2000141 ) // EOBJECT0 = unknown
        {
          if( player.getQuestUI8AL( getId() ) != 1 )
          {
            Scene00001( player ); // Scene00001: Normal(None), id=unknown
            // +Callback Scene00100: Normal(None), id=unknown
          }
          else
          {
            Scene00099( player ); // Scene00099: Normal(None), id=unknown
          }
        }
        if( actor == 2000147 || actorId == 2000147 ) // EOBJECT1 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00002( player ); // Scene00002: Normal(None), id=unknown
            // +Callback Scene00098: Normal(None), id=unknown
          }
          else
          {
            Scene00097( player ); // Scene00097: Normal(None), id=unknown
          }
        }
        if( actor == 2000148 || actorId == 2000148 ) // EOBJECT2 = unknown
        {
          if( player.getQuestUI8BH( getId() ) != 2 )
          {
            Scene00003( player ); // Scene00003: Normal(None), id=unknown
            // +Callback Scene00096: Normal(None), id=unknown
          }
          else
          {
            Scene00095( player ); // Scene00095: Normal(None), id=unknown
          }
        }
        if( actor == 2000149 || actorId == 2000149 ) // EOBJECT3 = unknown
        {
          if( player.getQuestUI8BL( getId() ) != 1 )
          {
            Scene00004( player ); // Scene00004: Normal(None), id=unknown
            // +Callback Scene00094: Normal(None), id=unknown
          }
          else
          {
            Scene00093( player ); // Scene00093: Normal(None), id=unknown
          }
        }
        break;
      }
      //seq 255 event item ITEM0 = UI8BH max stack 1
      //seq 255 event item ITEM1 = UI8BL max stack 2
      //seq 255 event item ITEM2 = UI8CH max stack 1
      case 255:
      {
        Scene00005( player ); // Scene00005: NpcTrade(Talk, TargetCanMove), id=PAULINE
        // +Callback Scene00092: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAULINE
        // +Callback Scene00091: Normal(None), id=unknown
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
    if( player.getQuestUI8AL( getId() ) == 1 )
      if( player.getQuestUI8BH( getId() ) == 2 )
        if( player.getQuestUI8BH( getId() ) == 2 )
          if( player.getQuestUI8BL( getId() ) == 1 )
          {
            player.setQuestUI8AL( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BH( getId(), 0 );
            player.setQuestUI8BL( getId(), 0 );
            player.setQuestUI8CH( getId(), 0 );
            player.setQuestUI8CL( getId(), 0 );
            player.setQuestUI8DH( getId(), 0 );
            player.updateQuest( getId(), 255 );
            player.setQuestUI8BH( getId(), 1 );
            player.setQuestUI8BL( getId(), 2 );
            player.setQuestUI8CH( getId(), 1 );
          }
  }

  void Scene00000( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling Scene00000: Normal(Talk, QuestOffer, QuestAccept, TargetCanMove), id=MONRANGUIN" );
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
    player.sendDebug( "SubFst038:65711 calling Scene00001: Normal(None), id=unknown" );
    Scene00100( player );
  }
  void Scene00100( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchTrue]Scene00100: Normal(None), id=unknown" );
    Scene00099( player );
  }
  void Scene00099( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchFalse]Scene00099: Normal(None), id=unknown" );
    player.setQuestUI8AL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00002( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling Scene00002: Normal(None), id=unknown" );
    Scene00098( player );
  }
  void Scene00098( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchTrue]Scene00098: Normal(None), id=unknown" );
    Scene00097( player );
  }
  void Scene00097( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchFalse]Scene00097: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00003( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling Scene00003: Normal(None), id=unknown" );
    Scene00096( player );
  }
  void Scene00096( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchTrue]Scene00096: Normal(None), id=unknown" );
    Scene00095( player );
  }
  void Scene00095( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchFalse]Scene00095: Normal(None), id=unknown" );
    player.setQuestUI8BH( getId(), player.getQuestUI8BH( getId() ) + 1 );
    checkProgressSeq1( player );
  }

  void Scene00004( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling Scene00004: Normal(None), id=unknown" );
    Scene00094( player );
  }
  void Scene00094( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchTrue]Scene00094: Normal(None), id=unknown" );
    Scene00093( player );
  }
  void Scene00093( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchFalse]Scene00093: Normal(None), id=unknown" );
    player.setQuestUI8BL( getId(), 1 );
    checkProgressSeq1( player );
  }

  void Scene00005( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling Scene00005: NpcTrade(Talk, TargetCanMove), id=PAULINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00092( player );
      }
    };
    player.playScene( getId(), 5, NONE, callback );
  }
  void Scene00092( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchTrue]Scene00092: Normal(Talk, QuestReward, QuestComplete, TargetCanMove), id=PAULINE" );
    auto callback = [ & ]( Entity::Player& player, const Event::SceneResult& result )
    {
      if( result.param1 > 0 && result.param2 == 1 )
      {
        Scene00091( player );
      }
    };
    player.playScene( getId(), 92, NONE, callback );
  }
  void Scene00091( Entity::Player& player )
  {
    player.sendDebug( "SubFst038:65711 calling [BranchChain]Scene00091: Normal(None), id=unknown" );
  }
};

EXPOSE_SCRIPT( SubFst038 );