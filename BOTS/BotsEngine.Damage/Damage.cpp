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

const bool BotsEngine::Damage::operator==(const DamageValue & value1, const DamageValue & value2)
{
	return value1.value == value2.value;
}

const DamageValue BotsEngine::Damage::operator+(const DamageValue & value1, const DamageValue & value2)
{
	return DamageValue(value1.value + value2.value);
}

const DamageValue BotsEngine::Damage::operator+(const DamageValue & value1, const int value2)
{
	if (value2 > 0)
	{
		return DamageValue(value1.GetValue() + static_cast<unsigned int>(value2));
	}
	else
	{
		unsigned int newValue = static_cast<unsigned int>(-value2);
		newValue = newValue < value1.value
			? value1.value - newValue
			: 0;
		return DamageValue(newValue);
	}
}

const DamageValue BotsEngine::Damage::operator+(const int value1, const DamageValue & value2)
{
	return value2 + value1;
}

ostream & BotsEngine::Damage::operator<<(ostream & stream, const DamageValue & damageValue)
{
	stream << damageValue.GetValue();
}
