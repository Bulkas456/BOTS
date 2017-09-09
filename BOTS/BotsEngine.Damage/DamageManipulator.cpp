#include "DamageManipulator.h"
#include "DamageType.h"

using namespace BotsEngine::Damage::Manipulator;
using namespace BotsEngine::Damage::DamageType;

DamageManipulator::DamageManipulator(const function<bool(const IDamageType&)> damageTypeFiler, const function<Damage(const Damage&)> damageManipulator)
	: damageTypeFiler(damageTypeFiler), damageManipulator(damageManipulator)
{
}

const Damage DamageManipulator::Manipulate(const ManipulatorContext & data)
{
	return this->damageTypeFiler(data.DamageType)
		    ? this->damageManipulator(data.Damage)
		    : data.Damage; 
}
