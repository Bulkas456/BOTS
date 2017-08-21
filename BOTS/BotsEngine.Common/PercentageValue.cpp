#include "PercentageValue.h"
#include <stdlib.h> 

using namespace BotsEngine::Common;

PercentageValue::PercentageValue(const int value)
	: value(value)
{
}

const int PercentageValue::GetValue() const
{
	return this->value;
}

const int PercentageValue::PositiveValue() const
{
	return this->Positive()
		    ? this->value
		    : -this->value;
}

const bool PercentageValue::Positive() const
{
	return this->value > 0;
}

PercentageValue::operator double() const
{
	return static_cast<double>(this->PositiveValue()) / 100.0;
};
