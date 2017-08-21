#include "DamageManipulator.h"
#include "..\BotsEngine.Common\PercentageValue.h"

using namespace BotsEngine::Common;
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

DamageValue ConstantNumberDamageManipulator::Manipulate(const DamageValue damageValue) const
{
	return damageValue + this->manipulatorValue;
}

PercentDamageManipulator::PercentDamageManipulator(const IDamageType & damageType, const PercentageValue manipulatorValue)
	: ManipulatorBase(damageType), ConstantValueManipulator(damageType, manipulatorValue)
{
}

DamageValue PercentDamageManipulator::Manipulate(const DamageValue damageValue) const
{
	return damageValue * this->manipulatorValue;
}


