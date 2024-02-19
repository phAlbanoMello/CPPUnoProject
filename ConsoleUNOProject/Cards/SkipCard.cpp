#include "SkipCard.h"

SkipCard::SkipCard(GameStateService& gsService, CardArt art, std::string cardValue) : SpecialCard(gsService, art, cardValue)
{
}

void SkipCard::Activate()
{
}

void SkipCard::Revert()
{
}
