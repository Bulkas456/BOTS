#include "Damage.h"
#include <stdlib.h> 

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

const DamageValue BotsEngine::Damage::operator-(const DamageValue & value1, const DamageValue & value2)
{
	const unsigned int damageValue = value2.value >= value1.value
		                              ? 0
		                              : value1.value - value2.value;
	return DamageValue(damageValue);
}

const DamageValue BotsEngine::Damage::operator*(const DamageValue & value1, const PercentageValue & value2)
{
	const double calculatedValue = round(static_cast<double>(value1.value) * static_cast<double>(value2));
	return DamageValue(static_cast<unsigned int>(calculatedValue));
}

const DamageValue BotsEngine::Damage::operator*(const PercentageValue & value1, const DamageValue & value2)
{
	return value2 * value1;
}

ostream & BotsEngine::Damage::operator<<(ostream & stream, const DamageValue & damageValue)
{
	stream << damageValue.GetValue();
}
