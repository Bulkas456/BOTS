#include "DamageType.h"


ostream & BotsEngine::Damage::operator<<(ostream & stream, const IDamageType & damageValue)
{
	stream << damageValue.GetType();
	const string & subType = damageValue.GetSubType();

	if (subType.length() > 0)
	{
		stream << "( " << subType << " )";
	}
}

BotsEngine::Damage::DamageType::DamageType(const string type, const string subType)
	: type(type), subType(subType)
{
}

const string & BotsEngine::Damage::DamageType::GetType() const
{
	return this->type;
}

const string & BotsEngine::Damage::DamageType::GetSubType() const
{
	return this->subType;
}
