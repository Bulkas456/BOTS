#include "stdafx.h"
#include "CppUnitTest.h"
#include "CppUnitTestAssert.h"
#include "../BotsEngine.Damage/DamageManipulator.h"
#include "../BotsEngine.Damage/DamageManipulatorMethods.h"
#include "../BotsEngine.Damage/DamageType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
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
			Damage damage(10);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			ManipulatorContext context{ damageType, damage };

			// Act
			Damage actual = manipulator.Manipulate(context);

			// Assert
			Assert::AreEqual(15u, actual.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntManipulatorWithNegativeValue_ShouldManipulateProperly)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(ConstantValueDamageManipulatorMethod, -5);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage damage(10);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			ManipulatorContext context{ damageType, damage };

			// Act
			Damage actual = manipulator.Manipulate(context);

			// Assert
			Assert::AreEqual(5u, actual.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntPercentManipulatorWithPositiveValue_ShouldManipulateProperly)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(PercentValueDamageManipulatorMethod, 50);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage damage(20);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			ManipulatorContext context{ damageType, damage };

			// Act
			Damage actual = manipulator.Manipulate(context);

			// Assert
			Assert::AreEqual(30u, actual.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntPercentManipulatorWithPositiveValue_ShouldManipulateProperly2)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(PercentValueDamageManipulatorMethod, 22);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage damage(15);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			ManipulatorContext context{ damageType, damage };

			// Act
			Damage actual = manipulator.Manipulate(context);

			// Assert
			Assert::AreEqual(18u, actual.GetValue());
		}

		TEST_METHOD(WhenManipulateWithIntPercentManipulatorWithNegativeValue_ShouldManipulateProperly2)
		{
			// Arrange
			IntValueDamageManipulator valueManipulator(PercentValueDamageManipulatorMethod, -23);
			DamageManipulator manipulator([](const IDamageType&) -> bool { return true; }, valueManipulator);
			Damage damage(17);
			BotsEngine::Damage::DamageType::DamageType damageType("type");
			ManipulatorContext context{ damageType, damage };

			// Act
			Damage actual = manipulator.Manipulate(context);

			// Assert
			Assert::AreEqual(13u, actual.GetValue());
		}
	};
}