#include "Card.h"
#include "CardFactory.h"

Card::Card(CardArt cardArt) : cardArt(cardArt)
{
}

ConsoleColor Card::GetColor() const
{
	return cardArt.color;
}

void Card::SetAction(std::function<void()> cardAction)
{
	action = std::make_shared<std::function<void()>>(cardAction);
}

void Card::InvokeAction()
{
	(*action)();
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
