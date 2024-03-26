#include "Card.h"
#include "CardFactory.h"

Card::Card(CardArt cardArt, std::string value) : _cardArt(cardArt), _cardValue(value)
{
}

ConsoleColor Card::GetColor() const
{
	return _cardArt.color;
}

void Card::SetAction(std::function<void(GameStateService&)> cardAction)
{
	_action = std::make_shared<std::function<void(GameStateService&)>>(std::move(cardAction));
}

void Card::InvokeAction()
{
	if (_action)
	{
		_action();
	}
}

void Card::PrintCardData()
{
	ConsoleService::Print(CardFactory::GetColorName(_cardArt.color));
}

void Card::DrawArt() const
{
}

CardArt Card::GetCardArt()
{
	return _cardArt;
}

std::string Card::GetCardValue() const
{
	return _cardValue;
}
