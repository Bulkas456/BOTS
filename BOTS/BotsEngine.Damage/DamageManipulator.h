#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "Damage.h"
#include "DamageType.h"
#include "../BotsEngine.Common/Manipulator.h"
#include "DamageData.h"

using namespace BotsEngine::Damage;
using namespace BotsEngine::Damage::DamageType;
using namespace BotsEngine::Common;
using namespace BotsEngine::Common::Manipulator;
using namespace std;

namespace BotsEngine
{
	namespace Damage
	{
		namespace Manipulator
		{
			typedef IManipulator<DamageData&, DamageData&> IDamageManipulator;

			class DamageManipulator : public virtual IDamageManipulator
			{
			private:
				const function<bool(const IDamageType&)> damageTypeFiler;
				const function<Damage(const Damage&)> damageManipulator;
			public:
				DamageManipulator(const function<bool(const IDamageType&)> damageTypeFiler, const function<Damage(const Damage&)> damageManipulator);
				DamageData& Manipulate(DamageData& data) const override;
			};
		}
	}
}