#pragma once
#include "CardFactory.h"

class NumberCard {
private:
    CardArt cardArt;

public:
    NumberCard(int number, ConsoleColor color);
    CardArt GetCardArt() const;
    void DrawArt() const;
};
