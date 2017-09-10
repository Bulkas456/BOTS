#include "stdafx.h"
#include "CppUnitTest.h"
#include "CppUnitTestAssert.h"
#include "../BotsEngine.Damage/DamageManipulator.h"
#include "../BotsEngine.Damage/DamageManipulatorMethods.h"
#include "../BotsEngine.Damage/DamageType.h"
#include "../BotsEngine.Damage/DamageData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BotsEngine::Damage;
using namespace BotsEngine::Damage::DamageType;
using namespace BotsEngine::Damage::Manipulator;
using namespace BotsEngine::Tests;

namespace BotsEngineTests
{
	TEST_CLASS(DamageManipulatorTests)
	{
	public:

		TEST_METHOD(WhenManipulateWithIntManipulatorWithPositiveValue_ShouldManipulateProperly)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(ConstantValueDamageManipulatorMethod, 5);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage min(10);
			Damage max(12);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			DamageData actual{ min, max, damageType };

			// Act
			manipulator.Manipulate(actual);

			// Assert
			Assert::AreEqual(15u, actual.Min.GetValue());
			Assert::AreEqual(17u, actual.Max.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntManipulatorWithNegativeValue_ShouldManipulateProperly)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(ConstantValueDamageManipulatorMethod, -5);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage min(10);
			Damage max(12);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			DamageData actual{ min, max, damageType };

			// Act
			manipulator.Manipulate(actual);

			// Assert
			Assert::AreEqual(5u, actual.Min.GetValue());
			Assert::AreEqual(7u, actual.Max.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntPercentManipulatorWithPositiveValue_ShouldManipulateProperly)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(PercentValueDamageManipulatorMethod, 50);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage min(10);
			Damage max(20);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			DamageData actual{ min, max, damageType };

			// Act
			manipulator.Manipulate(actual);

			// Assert
			Assert::AreEqual(15u, actual.Min.GetValue());
			Assert::AreEqual(30u, actual.Max.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntPercentManipulatorWithPositiveValue_ShouldManipulateProperly2)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(PercentValueDamageManipulatorMethod, 22);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage min(15);
			Damage max(22);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			DamageData actual{ min, max, damageType };

			// Act
			manipulator.Manipulate(actual);

			// Assert
			Assert::AreEqual(18u, actual.Min.GetValue());
			Assert::AreEqual(27u, actual.Max.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntPercentManipulatorWithNegativeValue_ShouldManipulateProperly2)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(PercentValueDamageManipulatorMethod, -23);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage min(17);
			Damage max(22);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			DamageData actual{ min, max, damageType };

			// Act
			manipulator.Manipulate(actual);

			// Assert
			Assert::AreEqual(13u, actual.Min.GetValue());
			Assert::AreEqual(17u, actual.Max.GetValue());
		}

		TEST_METHOD(WhenManipulateMoreThanOnce_ShouldManipulateProperly)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator1(PercentValueDamageManipulatorMethod, -23);
			DamageManipulator manipulator1([](const IDamageType&) -> bool { return true; }, valueManipulator1);
			IntValueDamageManipulator valueManipulator2(ConstantValueDamageManipulatorMethod, 5);
			DamageManipulator manipulator2([](const IDamageType&) -> bool { return true; }, valueManipulator2);
			Damage min(170);
			Damage max(220);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			DamageData actual{ min, max, damageType };

			// Act
			manipulator1.Manipulate(actual);
			manipulator2.Manipulate(actual);

			// Assert
			Assert::AreEqual(136u, actual.Min.GetValue());
			Assert::AreEqual(174u, actual.Max.GetValue());
		}
	};
}