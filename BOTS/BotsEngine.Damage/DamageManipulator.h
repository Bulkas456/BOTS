#pragma once
#include"Damage.h"
#include"DamageType.h"
#include "..\BotsEngine.Common\PercentageValue.h"
#include<vector>

using namespace BotsEngine::Common;
using namespace BotsEngine::Damage;
using namespace std;

namespace BotsEngine
{
	namespace Damage
	{
		namespace Manipulator
		{
			class IDamageManipulator
			{
			public:
				virtual ~IDamageManipulator()
				{
				};
				virtual const IDamageType & GetDamageType() const = 0;
				virtual DamageValue Manipulate(const DamageValue damageValue) const = 0;
			};

			class ManipulatorBase : public virtual IDamageManipulator
			{
			private:
				const IDamageType & damageType;

			public:
				ManipulatorBase(const IDamageType & damageType);
				const IDamageType & GetDamageType() const;
			};

			template<class TValue>
			class ConstantValueManipulator : public virtual ManipulatorBase
			{
			protected:
				const TValue manipulatorValue;

			public:
				ConstantValueManipulator(const IDamageType & damageType, const TValue manipulatorValue) 
					: ManipulatorBase(damageType), manipulatorValue(manipulatorValue)
				{
				};
			};

			class ConstantNumberDamageManipulator : public virtual ConstantValueManipulator<int>
			{
			public:
				ConstantNumberDamageManipulator(const IDamageType & damageType, const int manipulatorValue);
				DamageValue Manipulate(const DamageValue damageValue) const;
			};

			class PercentDamageManipulator : public virtual ConstantValueManipulator<PercentageValue>
			{
			public:
				PercentDamageManipulator(const IDamageType & damageType, const PercentageValue manipulatorValue);
				DamageValue Manipulate(const DamageValue damageValue) const;
			};
		}
	}
}