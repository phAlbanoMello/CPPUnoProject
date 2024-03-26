#pragma once
#include "CardEffect.h"

class WildEffect : public CardEffect {
public:
    void ApplyEffect(GameStateService& gameState) override;
};
