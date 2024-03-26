#pragma once
#include "CardEffect.h"

class PlusFourEffect : public CardEffect {
public:
    void ApplyEffect(GameStateService& gameState) override;
};
