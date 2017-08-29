#pragma once
#include<iostream>

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

			friend const Damage operator+(const Damage & value1, const double value2);
			friend const Damage operator+(const double value1, const Damage & value2);

			friend const Damage operator*(const Damage & value1, const double value2);
			friend const Damage operator*(const double value1, const Damage & value2);

			friend const Damage operator*(const Damage & value1, const int value2);
			friend const Damage operator*(const int value1, const Damage & value2);

			friend const Damage operator-(const Damage & value1, const Damage & value2);
		};

		inline ostream & operator<<(ostream & stream, const Damage & damage);
	}
}