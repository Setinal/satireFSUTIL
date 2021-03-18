#include "modules.h"

void modules::console::fixCLI()
{
    GetConsoleMode(modules::console::handle, &modules::console::mode);
    SetConsoleMode(handle, modules::console::mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING | DISABLE_NEWLINE_AUTO_RETURN);
    setlocale(LC_ALL, ".utf8");
    MoveWindow(modules::console::hWnd, 610, 300, 400, 280, TRUE);
    ShowScrollBar(modules::console::hWnd, SB_BOTH, FALSE);
    SetWindowLong(modules::console::hWnd, GWL_STYLE, GetWindowLong(modules::console::hWnd, GWL_STYLE) & ~(WS_MAXIMIZEBOX & WS_SIZEBOX));
    SetConsoleTitleA("");
}

void modules::pin::ascii()
{
    std::cout << R"(
8888888b. 8888888 888b    888
888   Y88b  888   8888b   888
888    888  888   88888b  888
888   d88P  888   888Y88b 888
8888888P"   888   888 Y88b888
888         888   888  Y88888
888         888   888   Y8888
888       8888888 888    Y888

)" << std::endl;
}

void modules::pin::drawMenu()
{
    modules::console::fixCLI();
    modules::console::changeColor(9);
    modules::pin::ascii();
    std::cout << "Enter PIN: ";
    std::string pass;
    char inputText;
    inputText = _getch();
    while (inputText != 13)
    {
        pass.push_back(inputText);
        std::cout << "*";
        inputText = _getch();
    }
    if (pass == "nigga")
    {
        modules::console::changeColor(5);
        system("cls");
        pin();
        std::cout << "Welcome." << std::endl;
    }
    else
    {

        system("cls");
        pin();
        std::cout << "Incorrect." << std::endl;
        Sleep(5000);
        exit(-1);
    }

}