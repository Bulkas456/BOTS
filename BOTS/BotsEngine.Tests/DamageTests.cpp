#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\BotsEngine.Damage\Damage.h"
#include "CppUnitTestAssert.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BotsEngine::Damage;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<>
			static std::wstring ToString<DamageValue>(const DamageValue & damage)
			{
				std::wstringstream s;	
				s << damage.GetValue(); 
				return s.str();
			}
		}
	}
}

namespace BotsEngineTests
{	
	TEST_CLASS(DamageTests)
	{
	public:
		
		TEST_METHOD(WhenAddDamageValueToDamageValue_ShouldAddProperly)
		{
			// Arrange
			DamageValue damage1(100);
			DamageValue damage2(5);
			DamageValue expected(105);

			// Act
			DamageValue actual = damage1 + damage2;

			// Assert
			Assert::AreEqual(actual, expected);
		}
	};
}