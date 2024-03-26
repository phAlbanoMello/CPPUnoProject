#pragma once
#include "CardEffect.h"

class ReverseEffect : public CardEffect {
public:
    void ApplyEffect(GameStateService& gameState) override;
};
