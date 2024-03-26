#include "NumberCard.h" 
#include "CardFactory.h"

NumberCard::NumberCard(CardArt cardArt, int number) : Card(cardArt, std::to_string(number)), number(number)
{
}

CardArt NumberCard::GetCardArt() const
{
    return _cardArt;
}

void NumberCard::DrawArt() const {
    for (const auto& frame : _cardArt.cardArtStrings) {
        ConsoleService::PrintWithColor(*frame, _cardArt.color);
    }
}

int NumberCard::GetNumber() const
{
    return number;
}

void NumberCard::PrintCardData()
{
    ConsoleService::Print(CardFactory::GetColorName(_cardArt.color));
    ConsoleService::Print(std::to_string(number));
}
