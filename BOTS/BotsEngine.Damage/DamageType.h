#pragma once

#include<string>
#include<iostream>

using namespace std;

namespace BotsEngine
{
	namespace Damage
	{
		namespace DamageType
		{
			class IDamageType
			{
			public:
				virtual ~IDamageType()
				{
				};
				virtual const string & GetType() const = 0;
				virtual const string & GetSubType() const = 0;
			};

			inline ostream & operator<<(ostream & stream, const IDamageType & damage);

			class DamageType : public virtual IDamageType
			{
			private:
				string type;
				string subType;

			public:
				DamageType(const string type, const string subType = "");
				const string & GetType() const;
				const string & GetSubType() const;
			};
		}
	}
}