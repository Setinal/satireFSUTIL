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

void modules::search::deleted()
{
    system(xorstr("cd C:%HOMEPATH%\\DESKTOP & fsutil usn readjournal c: csv | findstr /i /C:.exe | findstr /i /C:delete >> deleted_results.txt").crypt_get());
    MessageBox(nullptr, "Done!", "Finished", MB_OK);
}

void modules::search::renamed()
{
    system(xorstr("cd C:%HOMEPATH%\\DESKTOP & fsutil usn readjournal c: csv | findstr /i /C:.exe | findstr /i /C:rename >> renamed_results.txt").crypt_get());
    MessageBox(nullptr, "Done!", "Finished", MB_OK);
}

void modules::misc::deleteALL()
{
    char deletedFile[] = "C:%HOMEPATH%\\DESKTOP\\deleted_results.txt";
    if (remove(deletedFile) != 0)
    {
        std::cout << xorstr("Failed to delete file, error code: ").crypt_get() << GetLastError();
    }
    else
    {
        std::cout << xorstr("Deleted successfully!").crypt_get() << std::endl;
    }

    char renamedFile[] = "C:%HOMEPATH%\\DESKTOP\\renamed_results.txt";
    if (remove(renamedFile) != 0)
    {
        std::cout << xorstr("Failed to delete file, error code: ").crypt_get() << GetLastError();
    }
    else
    {
        std::cout << xorstr("Deleted successfully!").crypt_get() << std::endl;
    }
}

void modules::misc::deleteDELETED()
{
    char deletedFile[] = "C:%HOMEPATH%\\DESKTOP\\deleted_results.txt";

    if (remove(deletedFile) != 0)
    {
        std::cout << xorstr("Failed to delete file, error code: ").crypt_get() << GetLastError();
    }
    else
    {
        std::cout << xorstr("Deleted successfully!").crypt_get() << std::endl;
    }
}

void modules::misc::deleteRENAMED()
{
    char renamedFile[] = "C:%HOMEPATH%\\DESKTOP\\renamed_results.txt";
    if (remove(renamedFile) != 0)
    {
        std::cout << xorstr("Failed to delete file, error code: ").crypt_get() << GetLastError();
    }
    else
    {
        std::cout << xorstr("Deleted successfully!").crypt_get() << std::endl;
    }
}

int modules::search::openProcHack()
{
    system(xorstr("explorer https://processhacker.sourceforge.io/downloads.php").crypt_get());
    modules::console::changeColor(2);
    std::cout << xorstr("Explorer Open: Process Hacker").crypt_get() << std::endl;
    std::cout << xorstr("Link: https://processhacker.sourceforge.io/downloads.php").crypt_get() << std::endl;
    modules::console::changeColor(5);
    return 0;
}

int modules::search::userAssistView()
{
    system(xorstr("explorer https://www.nirsoft.net/utils/userassist_view.html").crypt_get());
    modules::console::changeColor(2);
    std::cout << xorstr("Explorer Open: User Assist View").crypt_get() << std::endl;
    std::cout << xorstr("Link: https://www.nirsoft.net/utils/userassist_view.html").crypt_get() << std::endl;
    modules::console::changeColor(5);
    return 0;
}

int modules::search::browsingHisView()
{
    system(xorstr("explorer https://www.nirsoft.net/utils/browsing_history_view.html").crypt_get());
    modules::console::changeColor(2);
    std::cout << xorstr("Explorer Open: BrowsingHistoryView").crypt_get() << std::endl;
    std::cout << xorstr("Link: https://www.nirsoft.net/utils/browsing_history_view.html").crypt_get() << std::endl;
    modules::console::changeColor(5);
    return 0;
}

int modules::search::searchVoidTools()
{
    system(xorstr("explorer https://www.voidtools.com/").crypt_get());
    modules::console::changeColor(2);
    std::cout << xorstr("Explorer Open: Voidtools Everything").crypt_get() << std::endl;
    std::cout << xorstr("Link: https://www.voidtools.com/").crypt_get() << std::endl;
    modules::console::changeColor(5);
    return 0;
}

void modules::pin::ascii()
{
    std::cout << xorstr(R"(
8888888b. 8888888 888b    888
888   Y88b  888   8888b   888
888    888  888   88888b  888
888   d88P  888   888Y88b 888
8888888P"   888   888 Y88b888
888         888   888  Y88888
888         888   888   Y8888
888       8888888 888    Y888

)").crypt_get() << std::endl;
}


void modules::pin::drawMenu()
{
    modules::console::fixCLI();
    modules::console::changeColor(9);
    modules::pin::ascii();
    std::cout << xorstr("Enter PIN: ").crypt_get();
    std::string pass;
    char inputText;
    inputText = _getch();
    while (inputText != 13)
    {
        pass.push_back(inputText);
        std::cout << xorstr("*").crypt_get();
        inputText = _getch();
    }
    if (pass == xorstr("PIN").crypt_get()) // You can change this, this is the access code.
    {
        modules::console::changeColor(5);
        system(xorstr("cls").crypt_get());
        pin();
        std::cout << xorstr("Welcome.").crypt_get() << std::endl;
    }
    else
    {

        system(xorstr("cls").crypt_get());
        pin();
        std::cout << xorstr("Incorrect.").crypt_get() << std::endl;
        Sleep(5000);
        exit(-1);
    }

}
