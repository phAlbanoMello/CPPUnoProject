#pragma once
#include "Card.h"

class GameStateService;

class SpecialCard : public Card
{
private:
	GameStateService& _gsService;
public:
	SpecialCard(GameStateService& gsService, CardArt cardArt, std::string cardValue);

	void PrintCardData() override;
	void DrawArt() const override;
	CardArt GetCardArt() const;
	std::string GetCardValue() const;
	virtual void Activate();
	virtual void Revert();
};

