#include<string>
#include "DamageType.h"

using namespace BotsEngine::Damage::DamageType;

ostream & BotsEngine::Damage::DamageType::operator<<(ostream & stream, const IDamageType & damage)
{
	stream << damage.GetType();
	const string & subType = damage.GetSubType();

	if (subType.length() > 0)
	{
		stream << "( " << subType << " )";
	}
}

DamageType::DamageType(const string type, const string subType)
	: type(type), subType(subType)
{
}

const string & DamageType::GetType() const
{
	return this->type;
}

const string & DamageType::GetSubType() const
{
	return this->subType;
}
