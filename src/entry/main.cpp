#include "main.h"

int main()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    std::cout << "Zed op" << std::endl;
    renderGUI();
}
