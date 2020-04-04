#pragma once
#include <string>

namespace DebugConsole
{
	class Exception
	{
	public:
		Exception() = default;
		Exception(std::wstring message);
		virtual const std::wstring& what() const noexcept;

	private:
		std::wstring message;
	};
}
