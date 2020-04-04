#pragma once
#include "Exception.h"

namespace DebugConsole
{
	class ConsoleException
		:
		public Exception
	{
	public:
		using Exception::Exception;
	};
}