#include "Card.h"
#include "CardFactory.h"

Card::Card(CardArt cardArt, std::string value) : cardArt(cardArt), cardValue(value)
{
}

ConsoleColor Card::GetColor() const
{
	return cardArt.color;
}

void Card::SetAction(std::function<void(Turn&)> cardAction)
{
	action = std::make_shared<std::function<void(Turn&)>>(std::move(cardAction));
}

void Card::InvokeAction(Turn& turn)
{
	if (action)
	{
		(*action)(turn);
	}
}

void Card::PrintCardData()
{
	ConsoleService::Print(CardFactory::GetColorName(cardArt.color));
}

void Card::DrawArt() const
{
}

CardArt Card::GetCardArt()
{
	return cardArt;
}

std::string Card::GetCardValue() const
{
	return cardValue;
}
