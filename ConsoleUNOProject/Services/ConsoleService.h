#ifndef CONSOLESERVICE_H
#define CONSOLESERVICE_H

#include <iostream>
#include <string>
#include "Service.h"

enum class ConsoleColor {
    Default = 7,
    Black = 0,
    Blue = 1,
    Green = 2,
    Red = 4,
    Yellow = 6,
};

struct Color {
    std::string name;
    ConsoleColor code;
};

class ConsoleService : public Service{
public:
    static void Print(const std::string& message);
    static void PrintWithColor(const std::string& message, const ConsoleColor color, bool endLine = true);
};

#endif

