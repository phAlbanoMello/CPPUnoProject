#pragma once
#include <vector>
#include <string>
#include "../Services/ConsoleService.h"
#include "../Cards/SpecialCard.h"
#include "NumberCard.h"

class CardFactory
{
public:
    static CardArt MakeCardArt(const std::string value, ConsoleColor color);
    static std::string GetColorName(ConsoleColor color);
    static std::shared_ptr<NumberCard> CreateNumberCard(int value, ConsoleColor color);
    static std::shared_ptr<NumberCard> CreateSpecialCard(Card cardType, ConsoleColor color);
    static std::vector<std::shared_ptr<Card>> CreateNumberCards();
    static void CreateCardsForColors(std::vector<std::shared_ptr<Card>>& numberCards, int iterations);
};


