#pragma once
#include <vector>
#include <memory>
#include "Damage.h"
#include "DamageType.h"
#include "../BotsEngine.Common/Manipulator.h"
#include "../BotsEngine.Common/Predicate.h"

using namespace BotsEngine::Damage;
using namespace BotsEngine::Damage::DamageType;
using namespace BotsEngine::Common;
using namespace BotsEngine::Common::Manipulator;

namespace BotsEngine
{
	namespace Damage
	{
		namespace Manipulator
		{
			struct ManipulatorContext
			{
				IDamageType& DamageType;
				Damage& Damage;
			};

			typedef IManipulator<const ManipulatorContext&, const Damage> IDamageManipulator;
			typedef std::shared_ptr<IPredicate<const IDamageType&>> IDamageTypeFiler;
			typedef const Damage (*DamageManipulatorMethod)(const Damage &, const int);

			class DamageManipulator : public virtual IDamageManipulator
			{
			private:
				const IDamageTypeFiler damageTypeFiler;
				const DamageManipulatorMethod damageManipulatorMethod;
				const int manipulatorData;
			public:
				DamageManipulator(const IDamageTypeFiler damageTypeFiler, DamageManipulatorMethod damageManipulatorMethod, const int manipulatorData);
				const Damage Manipulate(const ManipulatorContext& data);
			};
		}
	}
}