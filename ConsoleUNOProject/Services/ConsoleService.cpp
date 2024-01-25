#include "ConsoleService.h"
#include <windows.h>

// Helper function to set console color (Windows-specific)
void SetConsoleColor(ConsoleColor color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}

// Helper function to reset console color (Windows-specific)
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