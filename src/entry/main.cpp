#include "main.h"

int main()
{

    modules::pin::drawMenu();
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    std::cout << "Zed op" << std::endl;
    renderGUI();
}
