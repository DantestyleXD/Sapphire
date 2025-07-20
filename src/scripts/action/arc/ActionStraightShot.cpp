#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>
#include <Action/Action.h>
#include <StatusEffect/StatusEffect.h>

#include <Logging/Logger.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class ActionStraightShot : public Sapphire::ScriptAPI::ActionScript
{
public:
  ActionStraightShot() : Sapphire::ScriptAPI::ActionScript( 98 )
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

    auto dmg = action.calcDamage( Potency );
    pActionBuilder->damage( pSource, pTarget, dmg.first, dmg.second );

    auto statusStraightShot = pPlayer->getStatusEffectById( StraightShot );

    if( statusStraightShot != nullptr )
      pPlayer->removeStatusEffect( StraightShot );
      
    pActionBuilder->applyStatusEffectSelf( StraightShot, 20000, 0 );
    
  }
};

EXPOSE_SCRIPT( ActionStraightShot );