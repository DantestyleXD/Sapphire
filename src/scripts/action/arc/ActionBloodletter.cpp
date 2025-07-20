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

class ActionBloodletter : public Sapphire::ScriptAPI::ActionScript
{
public:
  ActionBloodletter() : Sapphire::ScriptAPI::ActionScript( 110 )
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

    auto dmg = action.calcDamage( Potency );
    pActionBuilder->damage( pSource, pTarget, dmg.first, dmg.second );
  }
};

EXPOSE_SCRIPT( ActionBloodletter );