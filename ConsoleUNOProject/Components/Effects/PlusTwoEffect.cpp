#include "PlusTwoEffect.h"
#include "../../Rules/BuyCardsRule.h"

PlusTwoEffect::PlusTwoEffect(ConsoleColor cardColor) : _cardColor(cardColor)
{
}

void PlusTwoEffect::ApplyEffect(GameStateService& gameState)
{
	BuyCardsRule buyCardsRule = BuyCardsRule(gameState, "Buy Two", 2, _cardColor);
	RulesService::

}
