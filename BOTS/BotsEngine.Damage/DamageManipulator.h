#pragma once
#include"Damage.h"
#include"DamageType.h"
#include<vector>

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

			class ConstantValueManipulator : public virtual ManipulatorBase
			{
			protected:
				const int manipulatorValue;

			public:
				ConstantValueManipulator(const IDamageType & damageType, const int manipulatorValue);
			};

			class ConstantNumberDamageManipulator : public virtual ConstantValueManipulator
			{
			public:
				ConstantNumberDamageManipulator(const IDamageType & damageType, const int manipulatorValue);
				DamageValue Manipulate(const DamageValue damageValue) const;
			};

			class PercentDamageManipulator : public virtual ConstantValueManipulator
			{
			public:
				PercentDamageManipulator(const IDamageType & damageType, const int manipulatorValue);
				DamageValue Manipulate(const DamageValue damageValue) const;
			};
		}
	}
}