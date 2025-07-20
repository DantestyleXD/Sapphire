#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class StatusEffectOpoOpoForm : public Sapphire::ScriptAPI::StatusEffectScript
{
public:
  StatusEffectOpoOpoForm() : Sapphire::ScriptAPI::StatusEffectScript( 107 )
  {
  }

  void onExpire( Entity::Chara& actor ) override
  {
    actor.removeStatusEffectById( { OpoOpoForm } );
  }
};

EXPOSE_SCRIPT( StatusEffectOpoOpoForm );