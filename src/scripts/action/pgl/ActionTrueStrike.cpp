#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>
#include <Action/Action.h>
#include <StatusEffect/StatusEffect.h>

#include <Logging/Logger.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class ActionTrueStrike : public Sapphire::ScriptAPI::ActionScript
{
public:
  ActionTrueStrike() : Sapphire::ScriptAPI::ActionScript( 54 )
  {
  }

  void onExecute( Sapphire::World::Action::Action& action ) override
  {
    auto pPlayer = action.getSourceChara()->getAsPlayer();
    auto pSource = action.getSourceChara();
    auto pTarget = action.getHitChara();
    auto pActionBuilder = action.getActionResultBuilder();

    if( !pPlayer || !pActionBuilder )
      return;

    auto Potency = 150;

    auto statusRaptor = pPlayer->getStatusEffectById( RaptorForm );

    if( pTarget->isPlayerBehindMe( pPlayer, -0.5f ) )
      Potency = 190;

    auto dmg = action.calcDamage( Potency );
    pActionBuilder->damage( pSource, pTarget, dmg.first, dmg.second );

    if( statusRaptor != nullptr )
      pPlayer->removeStatusEffect( RaptorForm );

    pActionBuilder->applyStatusEffectSelf( CoeurlForm, 10000, 0 );
  }
};

EXPOSE_SCRIPT( ActionTrueStrike );