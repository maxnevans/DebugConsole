#pragma once
#ifndef MAXNEVANS_DEBUG_CONSOLE_HEADER

#include "../src/Console.h"

#ifdef _DEBUG

#ifndef DEBUG_CONSOLE_MAIN

#ifndef ENABLE_DEBUG_CONSOLE
#define ENABLE_DEBUG_CONSOLE() DebugConsole::Console::init()
#endif // !ENABLE_DEBUG_CONSOLE

#ifndef DCONSOLE
#define DCONSOLE(wStreamOutput) DebugConsole::Console::getConsole() << wStreamOutput
#endif // !DCONSOLE

#else

#ifndef ENABLE_DEBUG_CONSOLE
#define ENABLE_DEBUG_CONSOLE() void(0)
#endif // !ENABLE_DEBUG_CONSOLE

#ifndef DCONSOLE
#define DCONSOLE(wStreamOutput) std::wcout << wStreamOutput
#endif // !DCONSOLE

#endif

#ifndef DCONSOLE
#define DCONSOLE(wStreamOutput) void(0)
#endif // !DCONSOLE

#else

#ifndef ENABLE_DEBUG_CONSOLE

#ifdef DEBUG_CONSOLE_MAIN

#define ENABLE_DEBUG_CONSOLE() FreeConsole()

#endif // DEBUG_CONSOLE_MAIN

#define ENABLE_DEBUG_CONSOLE()

#endif // !ENABLE_DEBUG_CONSOLE

#ifndef DCONSOLE
#define DCONSOLE(wStreamOutput) void(0)
#endif // !DCONSOLE

#endif // DEBUG

#endif // !MAXNEVANS_DEBUG_CONSOLE_HEADER