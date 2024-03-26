#pragma once
#include "CardEffect.h"

class SkipEffect : public CardEffect {
public:
    void ApplyEffect(GameStateService& gameState) override;
};
