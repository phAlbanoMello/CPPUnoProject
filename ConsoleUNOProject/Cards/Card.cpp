#include "Card.h"

std::string Card::GetId()
{
	return id;
}

ConsoleColor Card::GetColor()
{
	return color;
}

void Card::SetAction(std::function<void()> cardAction)
{
	action = std::make_shared<std::function<void()>>(cardAction);
}
