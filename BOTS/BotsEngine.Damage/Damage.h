#pragma once
#include "..\BotsEngine.Common\PercentageValue.h"
#include<iostream>

using namespace BotsEngine::Common;
using namespace std;

namespace BotsEngine
{
	namespace Damage
	{
		class DamageValue
		{
		private:
			unsigned int value;

		public:
			DamageValue(unsigned int value = 0);
			unsigned int GetValue() const;
		    friend const bool operator==(const DamageValue & value1, const DamageValue & value2);

			friend const DamageValue operator+(const DamageValue & value1, const DamageValue & value2);

			friend const DamageValue operator+(const DamageValue & value1, const int value2);
			friend const DamageValue operator+(const int value1, const DamageValue & value2);

			friend const DamageValue operator-(const DamageValue & value1, const DamageValue & value2);

			friend const DamageValue operator*(const DamageValue & value1, const PercentageValue & value2);
			friend const DamageValue operator*(const PercentageValue & value1, const DamageValue & value2);
		};

		inline ostream & operator<<(ostream & stream, const DamageValue & damageValue);
	}
}