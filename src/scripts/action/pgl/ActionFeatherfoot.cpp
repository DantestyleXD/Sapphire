#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>
#include <Action/Action.h>
#include <StatusEffect/StatusEffect.h>

#include <Logging/Logger.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class ActionFeatherfoot : public Sapphire::ScriptAPI::ActionScript
{
public:
  ActionFeatherfoot() : Sapphire::ScriptAPI::ActionScript( 55 )
  {
  }

  void onExecute( Sapphire::World::Action::Action& action ) override
  {
    auto pPlayer = action.getSourceChara()->getAsPlayer();
    auto pSource = action.getSourceChara();
    auto pActionBuilder = action.getActionResultBuilder();

    if( !pPlayer || !pActionBuilder )
      return;

    pActionBuilder->applyStatusEffectSelf( Featherfoot, 15000, 0 );
  }
};

EXPOSE_SCRIPT( ActionFeatherfoot );