#pragma once

#include <functional>
#include "Damage.h"
#include "../BotsEngine.Common/Manipulator.h"

using namespace std;
using namespace BotsEngine::Common::Manipulator;

namespace BotsEngine
{
	namespace Damage
	{
		namespace Manipulator
		{
			typedef ValueManipulator<Damage, const Damage&, const int> IntValueDamageManipulator;

			const Damage ConstantValueDamageManipulatorMethod(const Damage & damage, const int manipulatorValue);

			const Damage PercentValueDamageManipulatorMethod(const Damage & damage, const int manipulatorValue);
		}
	}
}