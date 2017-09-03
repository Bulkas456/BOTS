#pragma once

#include "Damage.h"

namespace BotsEngine
{
	namespace Damage
	{
		namespace Manipulator
		{
			const Damage ConstantValueDamageManipulatorMethod(const Damage & damage, const int manipulatorValue);

			const Damage PercentValueDamageManipulatorMethod(const Damage & damage, const int manipulatorValue);
		}
	}
}