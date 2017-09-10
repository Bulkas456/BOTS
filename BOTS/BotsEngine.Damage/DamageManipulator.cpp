#include "DamageManipulator.h"
#include "DamageType.h"

using namespace BotsEngine::Damage::Manipulator;
using namespace BotsEngine::Damage::DamageType;

DamageManipulator::DamageManipulator(const function<bool(const IDamageType&)> damageTypeFiler, const function<Damage(const Damage&)> damageManipulator)
	: damageTypeFiler(damageTypeFiler), damageManipulator(damageManipulator)
{
}

DamageData& DamageManipulator::Manipulate(DamageData & data) const
{
	if (this->damageTypeFiler(data.DamageType))
	{
		data.Min = this->damageManipulator(data.Min);
		data.Max = this->damageManipulator(data.Max);
	}

	return data;
}
