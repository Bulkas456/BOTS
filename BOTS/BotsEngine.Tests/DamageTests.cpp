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
			Assert::AreEqual(expected, actual);
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
			Assert::AreEqual(expected, actual);
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
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenAddNegativeIntToDamage_ShouldAddProperly)
		{
			// Arrange
			Damage value1(100);
			int value2(-5);
			Damage expected(95);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenAddDamageToNegativeInt_ShouldAddProperly)
		{
			// Arrange
			int value1(-5);
			Damage value2(100);
			Damage expected(95);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenAddDoubleToDamage_ShouldAddProperly)
		{
			// Arrange
			Damage value1(100);
			double value2(5.75);
			Damage expected(106);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenAddDamageToDoubleInt_ShouldAddProperly)
		{
			// Arrange
			double value1(100.4);
			Damage value2(5);
			Damage expected(105);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenAddNegativeDoubleToDamage_ShouldAddProperly)
		{
			// Arrange
			Damage value1(100);
			double value2(-5.3);
			Damage expected(95);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenAddDamageToNegativeDouble_ShouldAddProperly)
		{
			// Arrange
			double value1(-5.7);
			Damage value2(100);
			Damage expected(94);

			// Act
			Damage actual = value1 + value2;

			// Assert
			Assert::AreEqual(expected, actual);
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
			Assert::AreEqual(expected, actual);
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
			Assert::AreEqual(expected, actual);
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
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenMultiplyDamageWithInt_ShouldMultiplyProperly)
		{
			// Arrange
			Damage value1(5);
			int value2(5);
			Damage expected(25);

			// Act
			Damage actual = value1 * value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenMultiplyDamageWithNegativeInt_ShouldMultiplyProperly)
		{
			// Arrange
			Damage value1(5);
			int value2(-5);
			Damage expected(0);

			// Act
			Damage actual = value1 * value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenMultiplyDamageWithDouble_ShouldMultiplyProperly)
		{
			// Arrange
			Damage value1(5);
			double value2(5.7);
			Damage expected(29);

			// Act
			Damage actual = value1 * value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenMultiplyDamageWithDouble2_ShouldMultiplyProperly)
		{
			// Arrange
			Damage value1(5);
			double value2(5.3);
			Damage expected(27);

			// Act
			Damage actual = value1 * value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(WhenMultiplyDamageWithNegativeDouble_ShouldMultiplyProperly)
		{
			// Arrange
			Damage value1(5);
			double value2(-5);
			Damage expected(0);

			// Act
			Damage actual = value1 * value2;

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}