#include "NumberCard.h" 

NumberCard::NumberCard(int number, ConsoleColor color, CardArt art) : 
    number(number), color(color), cardArt(art)
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

ConsoleColor NumberCard::GetColor() const
{
    return color;
}

