#pragma once
#include <vector>
#include "../Services/ConsoleService.h"

struct CardArt {
    std::vector<std::shared_ptr<std::string>> cardArtStrings;
    ConsoleColor color;
};

class NumberCard {
private:
    CardArt cardArt;
    int number;
    ConsoleColor color;

public:
    NumberCard(int number, ConsoleColor color, CardArt cardArt);
   
    CardArt GetCardArt() const;
    void DrawArt() const;
    int GetNumber() const;
    ConsoleColor GetColor() const;
};
