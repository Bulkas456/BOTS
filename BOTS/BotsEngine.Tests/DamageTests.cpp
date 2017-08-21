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
			DamageValue value1(100);
			DamageValue value2(5);
			DamageValue expected(105);

			// Act
			DamageValue actual = value1 + value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenAddIntToDamageValue_ShouldAddProperly)
		{
			// Arrange
			DamageValue value1(100);
			int value2(5);
			DamageValue expected(105);

			// Act
			DamageValue actual = value1 + value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenAddDamageValueToInt_ShouldAddProperly)
		{
			// Arrange
			int value1(100);
			DamageValue value2(5);
			DamageValue expected(105);

			// Act
			DamageValue actual = value1 + value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenSubtractDamageValueFromDamageValueWhenTheFirstValueIsGreaterThanTheSecond_ShouldSubtractProperly)
		{
			// Arrange
			DamageValue value1(100);
			DamageValue value2(5);
			DamageValue expected(95);

			// Act
			DamageValue actual = value1 - value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenSubtractDamageValueFromDamageValueWhenTheFirstValueIsLowerThanTheSecond_ShouldSubtractProperly)
		{
			// Arrange
			DamageValue value1(5);
			DamageValue value2(100);
			DamageValue expected(0);

			// Act
			DamageValue actual = value1 - value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenSubtractDamageValueFromDamageValueWhenTheFirstValueIsEqualThanTheSecond_ShouldSubtractProperly)
		{
			// Arrange
			DamageValue value1(5);
			DamageValue value2(5);
			DamageValue expected(0);

			// Act
			DamageValue actual = value1 - value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenMultipliesDamageValueWithPositivePercentageValue_ShouldMultipleProperly)
		{
			// Arrange
			DamageValue value1(50);
			PercentageValue value2(5);
			DamageValue expected(3);

			// Act
			DamageValue actual = value1 * value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}

		TEST_METHOD(WhenMultipliesDamageValueWithNegativePercentageValue_ShouldMultipleProperly)
		{
			// Arrange
			DamageValue value1(50);
			PercentageValue value2(-5);
			DamageValue expected(3);

			// Act
			DamageValue actual = value1 * value2;

			// Assert
			Assert::AreEqual(actual, expected);
		}
	};
}