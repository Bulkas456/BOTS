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
			static std::wstring ToString<Damage>(const Damage & damage)
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
		
		TEST_METHOD(WhenAddDamageToDamage_ShouldAddProperly)
		{
			// Arrange
			Damage value1(100);
			Damage value2(5);
			Damage expected(105);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenAddIntToDamage_ShouldAddProperly)
		{
			// Arrange
			Damage value1(100);
			int value2(5);
			Damage expected(105);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenAddDamageToInt_ShouldAddProperly)
		{
			// Arrange
			int value1(100);
			Damage value2(5);
			Damage expected(105);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenSubtractDamageFromDamageWhenTheFirstValueIsGreaterThanTheSecond_ShouldSubtractProperly)
		{
			// Arrange
			Damage value1(100);
			Damage value2(5);
			Damage expected(95);

			// Act
			Damage actual = value1 - value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenSubtractDamageFromDamageWhenTheFirstValueIsLowerThanTheSecond_ShouldSubtractProperly)
		{
			// Arrange
			Damage value1(5);
			Damage value2(100);
			Damage expected(0);

			// Act
			Damage actual = value1 - value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenSubtractDamageFromDamageWhenTheFirstValueIsEqualThanTheSecond_ShouldSubtractProperly)
		{
			// Arrange
			Damage value1(5);
			Damage value2(5);
			Damage expected(0);

			// Act
			Damage actual = value1 - value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenMultipliesDamageWithPositivePercentageValue_ShouldMultipleProperly)
		{
			// Arrange
			Damage value1(50);
			PercentageValue value2(5);
			Damage expected(3);

			// Act
			Damage actual = value1 * value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenMultipliesDamageWithNegativePercentageValue_ShouldMultipleProperly)
		{
			// Arrange
			Damage value1(50);
			PercentageValue value2(-5);
			Damage expected(3);

			// Act
			Damage actual = value1 * value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}
	};
}