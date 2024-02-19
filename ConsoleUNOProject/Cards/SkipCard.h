#pragma once
#include "SpecialCard.h"

class SkipCard : public SpecialCard
{
public:
	SkipCard(GameStateService& gsService, CardArt art, std::string cardValue);
	void Activate() override;
	void Revert() override;
};

