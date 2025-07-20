#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>
#include <StatusEffect/StatusEffect.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class StatusEffectFeatherfoot : public Sapphire::ScriptAPI::StatusEffectScript
{
public:
  StatusEffectFeatherfoot() : Sapphire::ScriptAPI::StatusEffectScript( 99 )
  {
  }

  void onApply( Entity::Chara& actor ) override
  {
    auto status = actor.getStatusEffectById( Featherfoot );
    status->setModifier( Common::ParamModifier::EvasionPercent, 12 );
  }

  void onExpire( Entity::Chara& actor ) override
  {
    auto status = actor.getStatusEffectById( Featherfoot );
    status->setModifier( Common::ParamModifier::EvasionPercent, -12 );
    actor.removeStatusEffectById( { Featherfoot } );
  }
};

EXPOSE_SCRIPT( StatusEffectFeatherfoot );