#ifndef SATIREFSUTIL_MODULES_H
#define SATIREFSUTIL_MODULES_H

#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <conio.h>

#include "../dx11/gui/gui.h"

namespace modules
{
    class console
    {
    public:
        static auto inline handle = GetStdHandle(STD_OUTPUT_HANDLE);
        static auto inline hWnd = GetConsoleWindow();
        static inline DWORD mode = 0;

        static void fixCLI();

        static int changeColor(int cCode)
        {
            return SetConsoleTextAttribute(modules::console::handle, cCode);
        }
    };

    class pin
    {
    public:
        static void ascii();
        static void drawMenu();
    };
}

#endif //SATIREFSUTIL_MODULES_H
