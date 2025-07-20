#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class StatusEffectRaptorForm : public Sapphire::ScriptAPI::StatusEffectScript
{
public:
  StatusEffectRaptorForm() : Sapphire::ScriptAPI::StatusEffectScript( 108 )
  {
  }

  void onExpire( Entity::Chara& actor ) override
  {
    actor.removeStatusEffectById( { RaptorForm } );
  }
};

EXPOSE_SCRIPT( StatusEffectRaptorForm );