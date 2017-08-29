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

ConstantNumberDamageManipulator::ConstantNumberDamageManipulator(const IDamageType & damageType, const int manipulatorValue)
	: ManipulatorBase(damageType), ConstantValueManipulator(damageType, manipulatorValue)
{
}

Damage ConstantNumberDamageManipulator::Manipulate(const Damage damage) const
{
	return damage + this->manipulatorValue;
}

PercentDamageManipulator::PercentDamageManipulator(const IDamageType & damageType, const int manipulatorValue)
	: ManipulatorBase(damageType), ConstantValueManipulator(damageType, manipulatorValue)
{
}

Damage PercentDamageManipulator::Manipulate(const Damage damage) const
{
	return damage * (1 + static_cast<double>(this->manipulatorValue) / 100);
}