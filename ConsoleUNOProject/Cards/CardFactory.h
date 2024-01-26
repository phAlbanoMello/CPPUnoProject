#pragma once
#include <vector>
#include <string>
#include "../Services/ConsoleService.h"
#include "../Cards/SpecialCard.h"
#include "NumberCard.h"

class CardFactory
{
public :
    static CardArt MakeNumberCardArt(int value, ConsoleColor color);
    static std::string GetColorName(ConsoleColor color);
    static NumberCard CreateNumberCard(int value, ConsoleColor color);
    static std::vector<NumberCard> CreateNumberCards();
};


