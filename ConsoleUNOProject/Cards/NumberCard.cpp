#include "NumberCard.h" 
#include "CardFactory.h"

NumberCard::NumberCard(CardArt cardArt, int number) : Card(cardArt), number(number)
{
}

CardArt NumberCard::GetCardArt() const
{
    return cardArt;
}

void NumberCard::DrawArt() const {
    for (const auto& frame : cardArt.cardArtStrings) {
        ConsoleService::PrintWithColor(*frame, cardArt.color);
    }
}

int NumberCard::GetNumber() const
{
    return number;
}

void NumberCard::PrintCardData()
{
    ConsoleService::Print(CardFactory::GetColorName(cardArt.color));
    ConsoleService::Print(std::to_string(number));
}
