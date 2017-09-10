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
			DamageData data{ min, max, damageType };

			// Act
			DamageData actual = manipulator.Manipulate(data);

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
			DamageData data{ min, max, damageType };

			// Act
			DamageData actual = manipulator.Manipulate(data);

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
			DamageData data{ min, max, damageType };

			// Act
			DamageData actual = manipulator.Manipulate(data);

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
			DamageData data{ min, max, damageType };

			// Act
			DamageData actual = manipulator.Manipulate(data);

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
			DamageData data{ min, max, damageType };

			// Act
			DamageData actual = manipulator.Manipulate(data);

			// Assert
			Assert::AreEqual(13u, actual.Min.GetValue());
			Assert::AreEqual(17u, actual.Max.GetValue());
		}
	};
}