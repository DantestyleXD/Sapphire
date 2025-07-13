#include <ScriptObject.h>
#include <Actor/Player.h>

#include <datReader/DatCategories/bg/LgbTypes.h>
#include <datReader/DatCategories/bg/lgb.h>

#include "Territory/InstanceObjectCache.h"
#include "Territory/Territory.h"

#include <Exd/ExdData.h>
#include <Manager/PlayerMgr.h>
#include <Service.h>

using namespace Sapphire;

class LimsaToUldahWarpTaxi : public Sapphire::ScriptAPI::EventScript
{
public:
  LimsaToUldahWarpTaxi() :
    Sapphire::ScriptAPI::EventScript( 0x00020021 )
  {
  }

  void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
  {
   auto& exdData = Common::Service< Sapphire::Data::ExdData >::ref();

    auto warp = exdData.getRow< Excel::Warp >( eventId );
    if( !warp )
      return;

    auto qualifiedPreResult = [ this ]( Entity::Player& player, const Event::SceneResult& result )
    {
      eventMgr().playScene( player, result.eventId, 1, HIDE_HOTBAR, { 1 }, [ & ]( Entity::Player& player, const Event::SceneResult& result ) {
        if( result.getResult( 0 ) != 0 )
        {
          auto warp = this->exdData().getRow< Excel::Warp >( result.eventId );
          if( warp )
          {
            auto popRangeInfo = instanceObjectCache().getPopRangeInfo( warp->data().PopRange );
            if( popRangeInfo )
            {
              auto pTeri = teriMgr().getTerritoryByTypeId( popRangeInfo->m_territoryTypeId );
              warpMgr().requestMoveTerritory( player, Sapphire::Common::WARP_TYPE_TOWN_TRANSLATE,
                                              pTeri->getGuId(), popRangeInfo->m_pos, popRangeInfo->m_rotation );
            }
          }
        }
      } );
    };

    eventMgr().playScene( player, eventId, 0, HIDE_HOTBAR, { 1 }, qualifiedPreResult );
  }
};

EXPOSE_SCRIPT( LimsaToUldahWarpTaxi );