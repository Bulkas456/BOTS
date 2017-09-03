#pragma once

namespace BotsEngine
{
	namespace Common
	{
		template<class TData>
		class IPredicate
		{
		public:
			virtual bool Check(TData data) = 0;
		};
	}
}