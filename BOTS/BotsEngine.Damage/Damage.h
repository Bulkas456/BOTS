#pragma once
#include<iostream>

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
			const DamageValue operator+(const DamageValue & damageValue) const;
		};

		inline ostream & operator<<(ostream & stream, const DamageValue & damageValue);
	}
}