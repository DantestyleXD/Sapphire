#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/CommonAction.h>
#include <StatusEffect/StatusEffect.h>

using namespace Sapphire;
using namespace Sapphire::World::Action;

class StatusEffectGreasedLightning : public Sapphire::ScriptAPI::StatusEffectScript
{
public:
  StatusEffectGreasedLightning() : Sapphire::ScriptAPI::StatusEffectScript( 111 )
  {
  }

  void onApply( Entity::Chara& actor ) override
  {
    actor.getStatusEffectById( GreasedLightning )->setModifier( Common::ParamModifier::EvasionPercent, 12 );
  }

  void onExpire( Entity::Chara& actor ) override
  {
    actor.getStatusEffectById( GreasedLightning )->delModifier( Common::ParamModifier::EvasionPercent );
    actor.removeStatusEffectById( { GreasedLightning } );
  }
};

EXPOSE_SCRIPT( StatusEffectGreasedLightning );