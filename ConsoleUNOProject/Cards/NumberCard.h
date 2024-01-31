#pragma once
#include <vector>
#include "../Services/ConsoleService.h"
#include "../Cards/Card.h"

class NumberCard : public Card {
private:
    int number;
public:
    NumberCard(CardArt cardArt, int number);
   
    CardArt GetCardArt() const;
    int GetNumber() const;
    void PrintCardData() override;
    void DrawArt() const override;
};
