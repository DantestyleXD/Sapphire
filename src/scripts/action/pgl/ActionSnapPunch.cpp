#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>
#include <Action/Action.h>
#include <StatusEffect/StatusEffect.h>

#include <Logging/Logger.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class ActionSnapPunch : public Sapphire::ScriptAPI::ActionScript
{
public:
  ActionSnapPunch() : Sapphire::ScriptAPI::ActionScript( 56 )
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

    auto Potency = 140;

    if( pTarget->isPlayerOnFlankOfMe( pPlayer, -0.5f ) )
      Potency = 180;    
      
    auto dmg = action.calcDamage( Potency );
    pActionBuilder->damage( pSource, pTarget, dmg.first, dmg.second );

    auto statusCoeurl = pPlayer->getStatusEffectById( CoeurlForm );

    if (statusCoeurl != nullptr)
      pPlayer->removeStatusEffect( CoeurlForm );

    pActionBuilder->applyStatusEffectSelf( OpoOpoForm, 10000, 0 );

    auto duration = 14000;

    if( pTarget->isPlayer() )
      duration = 28000;

    pActionBuilder->applyStatusEffectSelf( GreasedLightning, duration, 0 );
  }
};

EXPOSE_SCRIPT( ActionSnapPunch );