#pragma once
#include "../../Services/GameService.h"

class CardEffect {
public:
    virtual void ApplyEffect(GameStateService&) = 0;
    virtual ~CardEffect() = default;
};

