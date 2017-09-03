#include "DamageManipulator.h"
#include "DamageType.h"

using namespace BotsEngine::Damage::Manipulator;
using namespace BotsEngine::Damage::DamageType;

DamageManipulator::DamageManipulator(const IDamageTypeFiler damageTypeFiler, DamageManipulatorMethod damageManipulatorMethod, const int manipulatorData)
	: damageTypeFiler(damageTypeFiler), damageManipulatorMethod(damageManipulatorMethod), manipulatorData(manipulatorData)
{
}

const Damage DamageManipulator::Manipulate(const ManipulatorContext & data)
{
	return this->damageTypeFiler->Check(data.DamageType)
		    ? this->damageManipulatorMethod(data.Damage, this->manipulatorData)
		    : data.Damage;
}
