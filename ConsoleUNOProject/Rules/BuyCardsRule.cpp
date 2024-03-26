#include "BuyCardsRule.h"

BuyCardsRule::BuyCardsRule(GameStateService& gameState, std::string ruleID, int amountOfCardsToBuy, ConsoleColor nextTurnColor)
	: Rule(gameState, ruleID), _amountOfCardsToBuy(amountOfCardsToBuy), _nextTurnColor(nextTurnColor)
{
}

void BuyCardsRule::activate()
{
    _isActive = true;
    for (std::shared_ptr<Player>& target : _targets)
    {
        std::vector<std::shared_ptr<Card>> incomingCards;
        for (size_t i = 0; i < _amountOfCardsToBuy; i++)
        {
            if (_gameStateService.GetDrawPile().GetCards().size() >= _amountOfCardsToBuy)
            {
                incomingCards.push_back(_gameStateService.GetDrawPile().GetNextCard());
            }
        }
        target->GetHand()->ReceiveCards(incomingCards);
    }

    _gameStateService.ChangeGameColor(_nextTurnColor);
}

void BuyCardsRule::deactivate()
{
    _isActive = false;
}

bool BuyCardsRule::isActive() const
{
	return _isActive;
}

void BuyCardsRule::SetTargets(std::vector<std::shared_ptr<Player>> targets)
{
	_targets = targets;
}

std::vector<std::shared_ptr<Player>>& BuyCardsRule::GetTargets()
{
	return _targets;
}
