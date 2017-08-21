#include "DamageManipulator.h"
#include <stdlib.h> 

using namespace BotsEngine::Damage::Manipulator;

ManipulatorBase::ManipulatorBase(const IDamageType & damageType)
	: damageType(damageType)
{
}

const IDamageType & ManipulatorBase::GetDamageType() const
{
	return this->damageType;
}

ConstantValueManipulator::ConstantValueManipulator(const IDamageType & damageType, const int manipulatorValue)
	: ManipulatorBase(damageType), manipulatorValue(manipulatorValue)
{
}

ConstantNumberDamageManipulator::ConstantNumberDamageManipulator(const IDamageType & damageType, const int manipulatorValue)
	: ManipulatorBase(damageType), ConstantValueManipulator(damageType, manipulatorValue)
{
}

DamageValue ConstantNumberDamageManipulator::Manipulate(const DamageValue damageValue) const
{
	return damageValue + this->manipulatorValue;
}

PercentDamageManipulator::PercentDamageManipulator(const IDamageType & damageType, const int manipulatorValue)
	: ManipulatorBase(damageType), ConstantValueManipulator(damageType, manipulatorValue)
{
}

DamageValue PercentDamageManipulator::Manipulate(const DamageValue damageValue) const
{
	int manipulator = abs(this->manipulatorValue);
	unsigned int calculatedManipulator = damageValue * (static_cast<double>(manipulator) / 100);
	return this->manipulatorValue < 0
		    ? DamageValue();
}


