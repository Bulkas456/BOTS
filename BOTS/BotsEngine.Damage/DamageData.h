#pragma once

#include "Damage.h"
#include "DamageType.h"

using namespace BotsEngine::Damage::DamageType;

namespace BotsEngine
{
	namespace Damage
	{
		struct DamageData
		{
			Damage Min;
			Damage Max;
			const IDamageType& DamageType;
		};
	}
}