#include "DamageManipulatorMethods.h"
#include "Damage.h"

using namespace BotsEngine::Damage;

const Damage BotsEngine::Damage::Manipulator::ConstantValueDamageManipulatorMethod(const Damage & damage, const int manipulatorValue)
{
	return damage + manipulatorValue;
}

const Damage BotsEngine::Damage::Manipulator::PercentValueDamageManipulatorMethod(const Damage & damage, const int manipulatorValue)
{
	return damage * (1.0 + static_cast<double>(manipulatorValue) / 100.0);
}
