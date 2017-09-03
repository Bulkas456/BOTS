#include "stdafx.h"
#include "CppUnitTest.h"
#include "CppUnitTestAssert.h"
#include "../BotsEngine.Damage/DamageType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BotsEngine::Damage::DamageType;
using namespace BotsEngine::Tests;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<>
			static std::wstring ToString<IDamageType>(const IDamageType & damageType)
			{
				std::wstringstream s;
				s << StringToWstring(damageType.GetType());
				return s.str();
			}
		}
	}
}

namespace BotsEngineTests
{
	TEST_CLASS(DamageTypeTests)
	{
	public:

		TEST_METHOD(WhenCreated_ShouldCreateProperly)
		{
			// Arrange
			wstring expectedType = L"type";
			wstring expectedSubType = L"subtype";

			// Act
			DamageType actual("type", "subtype");

			// Assert
			Assert::AreEqual(StringToWstring(actual.GetType()), expectedType);
			Assert::AreEqual(StringToWstring(actual.GetSubType()), expectedSubType);
		}
	};
}