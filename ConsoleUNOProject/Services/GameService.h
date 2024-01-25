#pragma once
#include "Service.h"
#include "../Cards/NumberCard.h"

class GameService : public Service
{
public:
    void Init() override;
    void DrawCards(const std::vector<NumberCard>& cards);
};

