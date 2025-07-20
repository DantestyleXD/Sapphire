#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Actor/BNpc.h>
#include <Action/CommonAction.h>
#include <Action/Action.h>
#include <StatusEffect/StatusEffect.h>

#include <Logging/Logger.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class ActionBootshine : public Sapphire::ScriptAPI::ActionScript
{
public:
  ActionBootshine() : Sapphire::ScriptAPI::ActionScript( 53 )
  {
  }

  static constexpr auto Potency = 150;

  void onExecute( Sapphire::World::Action::Action& action ) override
  {
    auto pPlayer = action.getSourceChara()->getAsPlayer();
    auto pSource = action.getSourceChara();
    auto pTarget = action.getHitChara();
    auto pActionBuilder = action.getActionResultBuilder();

    if( !pPlayer || !pActionBuilder )
      return;

    auto statusOpo = pPlayer->getStatusEffectById( OpoOpoForm );
    auto critRateVal = pPlayer->getStatValue( Common::BaseParam::CriticalHit );

    if (statusOpo != nullptr && pTarget->isPlayerBehindMe(pPlayer, -0.5f))
    {
      pPlayer->setStatValue( Common::BaseParam::CriticalHit, 100 );
    }
      
    auto dmg = action.calcDamage( Potency );
    pActionBuilder->damage( pSource, pTarget, dmg.first, dmg.second );

    // TEMP
    // The real logic need to be implemented into pActionBuilder on damage method
    if (pTarget->isBattleNpc())
      pTarget->getAsBNpc()->hateListAdd( pPlayer, 1 );
    // else pvp

    if( !pPlayer->isInCombat() )
      pPlayer->setInCombat( true );

    ////////////////////////

    if( statusOpo != nullptr )
    {
      pPlayer->setStatValue( Common::BaseParam::CriticalHit, critRateVal );
      pPlayer->removeStatusEffect( OpoOpoForm );
    }

    pActionBuilder->applyStatusEffectSelf( RaptorForm, 10000, 0 );
  }
};

EXPOSE_SCRIPT( ActionBootshine );