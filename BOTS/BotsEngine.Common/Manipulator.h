#pragma once

#include <functional>

using namespace std;

namespace BotsEngine 
{
	namespace Common
	{
		namespace Manipulator
		{
			template<class TInput, class TOutput>
			class IManipulator
			{
			public:
				virtual ~IManipulator()
				{
				};
				virtual TOutput Manipulate(TInput data) const = 0;
			};

			template<class TManipulatedValueInput, class TManipulatedValueResult, class TValue>
			class ValueManipulator
			{
			private:
				const function<TManipulatedValueResult(TManipulatedValueInput, TValue)> manipulator;
				TValue value;
			public:
				ValueManipulator(const function<TManipulatedValueResult(TManipulatedValueInput, TValue)> manipulator, TValue value)
					: manipulator(manipulator), value(value)
				{
				}

				TManipulatedValueResult operator()(TManipulatedValueInput data) const
				{
					return this->manipulator(data, this->value);
				}
			};
		}
	}
}