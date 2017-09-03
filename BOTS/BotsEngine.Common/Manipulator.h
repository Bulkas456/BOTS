#pragma once

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
		}
	}
}