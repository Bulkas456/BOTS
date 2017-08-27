#include "Damage.h"
#include <stdlib.h> 

using namespace BotsEngine::Damage;

Damage::Damage(unsigned int value)
	: value(value)
{
}

unsigned int Damage::GetValue() const
{
	return this->value;
}

const bool BotsEngine::Damage::operator==(const Damage & value1, const Damage & value2)
{
	return value1.value == value2.value;
}

const Damage BotsEngine::Damage::operator+(const Damage & value1, const Damage & value2)
{
	return Damage(value1.value + value2.value);
}

const Damage BotsEngine::Damage::operator+(const Damage & value1, const int value2)
{
	if (value2 > 0)
	{
		return Damage(value1.GetValue() + static_cast<unsigned int>(value2));
	}
	else
	{
		unsigned int newValue = static_cast<unsigned int>(-value2);
		newValue = newValue < value1.value
			? value1.value - newValue
			: 0;
		return Damage(newValue);
	}
}

const Damage BotsEngine::Damage::operator+(const int value1, const Damage & value2)
{
	return value2 + value1;
}

const Damage BotsEngine::Damage::operator-(const Damage & value1, const Damage & value2)
{
	const unsigned int damage = value2.value >= value1.value
		                              ? 0
		                              : value1.value - value2.value;
	return Damage(damage);
}

const Damage BotsEngine::Damage::operator*(const Damage & value1, const PercentageValue & value2)
{
	const double calculatedValue = round(static_cast<double>(value1.value) * static_cast<double>(value2));
	return Damage(static_cast<unsigned int>(calculatedValue));
}

const Damage BotsEngine::Damage::operator*(const PercentageValue & value1, const Damage & value2)
{
	return value2 * value1;
}

ostream & BotsEngine::Damage::operator<<(ostream & stream, const Damage & damage)
{
	stream << damage.GetValue();
}
