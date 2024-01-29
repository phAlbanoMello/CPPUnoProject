#include "ConsoleService.h"
#include <windows.h>

void SetConsoleColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

void ResetConsoleColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(ConsoleColor::Default));
}

void ConsoleService::Print(const std::string& message) {
    std::cout << message << std::endl;
}

void ConsoleService::PrintWithColor(const std::string& message, const ConsoleColor color, bool endLine)
{
    SetConsoleColor(color);

    std::string lineEnding = endLine ? "\n" : "";
    std::cout << message << lineEnding;

    ResetConsoleColor();
}

void ConsoleService::SkipLines(int lineCount)
{
    for (size_t i = 0; i < lineCount; i++)
    {
        std::cout << std::endl;
    }
}

void ConsoleService::PrintDivisor(int lineCount)
{
    for (size_t i = 0; i < lineCount; i++)
    {
        std::cout <<"===========================================================" << std::endl;
    }
}


void ConsoleService::Clear() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[H";
#endif
}
