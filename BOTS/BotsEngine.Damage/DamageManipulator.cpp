#include "DamageManipulator.h"

using namespace BotsEngine::Damage::Manipulator;

ManipulatorBase::ManipulatorBase(const IDamageType & damageType)
	: damageType(damageType)
{
}

const IDamageType & ManipulatorBase::GetDamageType() const
{
	return this->damageType;
}

ConstantNumberDamageManipulator::ConstantNumberDamageManipulator(const IDamageType & damageType, int manipulatorValue)
	: ManipulatorBase(damageType), manipulatorValue(manipulatorValue)
{
}

DamageValue ConstantNumberDamageManipulator::Manipulate(const DamageValue damageValue) const
{
	return damageValue + this->manipulatorValue;
}
