#include "NumberCard.h"

NumberCard::NumberCard(int number, ConsoleColor color) {
    cardArt = CardFactory::MakeNumberCardArt(number, color);
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

