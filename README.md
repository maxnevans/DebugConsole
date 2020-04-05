# Windows Debug Console - wWinMain and main entry points

### Console works only with `wchar_t` characters for now!

How to:
- Include header file `include/DebugConsole.h`
- Include static lib `DebugConsole.lib`
- Define macro:
    - If use `main` entry point:
    ```C++  
    #define DEBUG_CONSOLE_MAIN
    ```
    - If use `wWinMain` entry point: __do not define anything__
- Initialize debug console by invoking macro:
    ```C++
    ENABLE_DEBUG_CONSOLE();
    ```
- Use it like this:
    ```C++
    ...

    DCONSOLE(L"Hello world!\n");

    ...

    int x = 10, y = 20;
    DCONSOLE(L"Click: (" << x << L',' << y << L")\n");

    ...
    ```
- Works with:
    - `std::wstring`
    - `std::wstring_view`
    - `const wchar_t*`
    - `char`
    - `unigned char`
    - `short`
    - `unsigned short`
    - `int`
    - `unsigned int`
    - `long`
    - `unsigned long`
    - `long long`
    - `unsigned lon long`
    - `float`
    - `double`