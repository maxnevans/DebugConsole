#include "Console.h"
#include "ConsoleException.h"
#include <cassert>

std::unique_ptr<DebugConsole::Console> DebugConsole::Console::instance;

DebugConsole::Console::Console()
{
    if (AllocConsole() == FALSE)
    {
        assert(false && "Failed to create second console!");
    }
}

DebugConsole::Console::~Console()
{
	FreeConsole();
}

DebugConsole::Console& DebugConsole::Console::operator<<(std::wstring message)
{
    if (WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), message.c_str(), message.size(), nullptr, nullptr) == FALSE)
    {
        throw ConsoleException(L"Failed to write to console!");
    }
    return *this;
}

DebugConsole::Console& DebugConsole::Console::getConsole()
{
    if (!instance)
    {
        instance = std::unique_ptr<Console>{new Console()};
    }

    return *instance;
}
