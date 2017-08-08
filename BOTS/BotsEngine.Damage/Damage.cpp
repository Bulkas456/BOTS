#include "Damage.h"
using namespace BotsEngine::Damage;

DamageValue::DamageValue(unsigned int value)
	: value(value)
{
}

unsigned int DamageValue::GetValue() const
{
	return this->value;
}

const DamageValue DamageValue::operator+(const DamageValue & damageValue) const
{
	return DamageValue(this->value + damageValue.value);
}

ostream & BotsEngine::Damage::operator<<(ostream & stream, const DamageValue & damageValue)
{
	stream << damageValue.GetValue();
}
