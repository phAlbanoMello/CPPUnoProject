#pragma once
#include "CardEffect.h"

class PlusTwoEffect : public CardEffect {
private:
    ConsoleColor _cardColor;
public:
    PlusTwoEffect(ConsoleColor cardColor);
    void ApplyEffect(GameStateService& gameState) override;
};
