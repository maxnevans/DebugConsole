#pragma once
#include <windows.h>
#include <memory>
#include <string>
#include <sstream>
#include <cassert>

namespace DebugConsole
{
	class Console
	{
	private:
		Console()
		{
			assert(AllocConsole() != FALSE);
		}

	public:
		~Console()
		{
			FreeConsole();
		}
		Console(const Console&) = delete;
		Console& operator=(const Console&) = delete;

		Console& operator<<(std::wstring_view message)
		{
			assert(WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), message.data(), message.size(), nullptr, nullptr) != FALSE);
			return *this;
		}

		Console& operator<<(const wchar_t* message)
		{
			std::wstring_view view = message;
			assert(WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), view.data(), view.size(), nullptr, nullptr) != FALSE);
			return *this;
		}

		Console& operator<<(const std::wstring& message)
		{
			assert(WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), message.c_str(), message.size(), nullptr, nullptr) != FALSE);
			return *this;
		}

		Console& operator<<(wchar_t character)
		{
			assert(WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), &character, 1, nullptr, nullptr) != FALSE);
			return *this;
		}
		
		template<typename T>
		Console& operator<<(T number)
		{
			std::wstring message = std::to_wstring(number);
			assert(WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), message.c_str(), message.size(), nullptr, nullptr) != FALSE);
			return *this;
		}

		static Console& getConsole()
		{
			assert(instance);
			return *instance;
		}
		static void init()
		{
			assert(!instance);
			instance = std::unique_ptr<Console>{ new Console() };
		}

	private:
		static std::unique_ptr<Console> instance;
	};
}
