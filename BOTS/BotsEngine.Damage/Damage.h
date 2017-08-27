#pragma once
#include "..\BotsEngine.Common\PercentageValue.h"
#include<iostream>

using namespace BotsEngine::Common;
using namespace std;

namespace BotsEngine
{
	namespace Damage
	{
		class Damage
		{
		private:
			unsigned int value;

		public:
			Damage(unsigned int value = 0);
			unsigned int GetValue() const;
		    friend const bool operator==(const Damage & value1, const Damage & value2);

			friend const Damage operator+(const Damage & value1, const Damage & value2);

			friend const Damage operator+(const Damage & value1, const int value2);
			friend const Damage operator+(const int value1, const Damage & value2);

			friend const Damage operator-(const Damage & value1, const Damage & value2);

			friend const Damage operator*(const Damage & value1, const PercentageValue & value2);
			friend const Damage operator*(const PercentageValue & value1, const Damage & value2);
		};

		inline ostream & operator<<(ostream & stream, const Damage & damage);
	}
}