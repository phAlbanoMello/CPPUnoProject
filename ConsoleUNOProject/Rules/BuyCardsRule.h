#pragma once
#include "Rule.h"
#include "../Services/ConsoleService.h"

class BuyCardsRule : public Rule
{
private:
	int _amountOfCardsToBuy;
	ConsoleColor _nextTurnColor;
public:
	BuyCardsRule(GameStateService& gameState, std::string ruleID, int amountOfCardsToBuy, ConsoleColor nextTurnColor);
	// Inherited via Rule
	void activate() override;

	void deactivate() override;

	bool isActive() const override;

	void SetTargets(std::vector<std::shared_ptr<Player>> targets) override;
	std::vector<std::shared_ptr<Player>>& GetTargets() override;
};

