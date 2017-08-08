#pragma once
#include<string>
#include<iostream>

using namespace std;

namespace BotsEngine
{
	namespace Damage
	{
		class IDamageType
		{
		public:
			virtual const string & GetType() const = 0;
			virtual const string & GetSubType() const = 0;
		};

		inline ostream & operator<<(ostream & stream, const IDamageType & damageValue);

		class DamageType : public IDamageType
		{
		private:
			string type;
			string subType;

		public:
			DamageType(string type, string subType = "");
			const string & GetType() const;
			const string & GetSubType() const;
		};
	}
}