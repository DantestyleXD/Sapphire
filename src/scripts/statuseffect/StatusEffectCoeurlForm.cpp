#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class StatusEffectCoeurlForm : public Sapphire::ScriptAPI::StatusEffectScript
{
public:
  StatusEffectCoeurlForm() : Sapphire::ScriptAPI::StatusEffectScript( 109 )
  {
  }

  void onExpire( Entity::Chara& actor ) override
  {
    actor.removeStatusEffectById( { CoeurlForm } );
  }
};

EXPOSE_SCRIPT( StatusEffectCoeurlForm );