#pragma once

namespace BotsEngine
{
	namespace Common
	{
		class PercentageValue
		{
		private:
			const int value;

		public:
			PercentageValue(const int value);
			const int GetValue() const;
			const int PositiveValue() const;
			const bool Positive() const;
		    operator double() const;
		};
	}
}