#pragma once
#include <vector>
#include "../Services/ConsoleService.h"

struct CardArt {
    std::vector<std::shared_ptr<std::string>> cardArtStrings;
    ConsoleColor color;
};

class CardFactory
{
public :
    static CardArt MakeNumberCardArt(int number, ConsoleColor color);
    static std::string GetColorName(ConsoleColor color);
};


