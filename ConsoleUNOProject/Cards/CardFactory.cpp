#include "CardFactory.h"

std::shared_ptr<std::string> CreateFrameString(const std::string& frame) {
    std::shared_ptr<std::string> frameString = std::make_shared<std::string>(frame);
    return frameString;
}

CardArt CardFactory::MakeNumberCardArt(int value, ConsoleColor color) {
    CardArt cardArt;

    std::string borderFrame = "|======|";
    std::string bodyFrame = "|      |";
    std::string valueFrame = "|  {0}   |";

    size_t valuePos = valueFrame.find("{0}");
    valueFrame.replace(valuePos, 3, std::to_string(value));

    std::string colorizedBodyFrame = "|" + GetColorName(color) + "|";

    cardArt.cardArtStrings.push_back(CreateFrameString(borderFrame));
    cardArt.cardArtStrings.push_back(CreateFrameString(colorizedBodyFrame));
    cardArt.cardArtStrings.push_back(CreateFrameString(bodyFrame));
    cardArt.cardArtStrings.push_back(CreateFrameString(valueFrame));
    cardArt.cardArtStrings.push_back(CreateFrameString(bodyFrame));
    cardArt.cardArtStrings.push_back(CreateFrameString(colorizedBodyFrame));
    cardArt.cardArtStrings.push_back(CreateFrameString(borderFrame));

    cardArt.color = color;

    return cardArt;
}

std::string CardFactory::GetColorName(ConsoleColor color) {
    switch (color) {
    case ConsoleColor::Red:
        return " red  ";
    case ConsoleColor::Yellow:
        return "yellow";
    case ConsoleColor::Wild:
        return "black ";
    case ConsoleColor::Blue:
        return " blue ";
    case ConsoleColor::Green:
        return "green ";
    default:
        return "      ";
    }
}

std::shared_ptr<NumberCard> CardFactory::CreateNumberCard(int value, ConsoleColor color)
{
    CardArt art = MakeNumberCardArt(value, color);
    NumberCard numberCard = NumberCard{ art, value };
    return std::make_shared<NumberCard>(numberCard);
}

std::vector<std::shared_ptr<Card>> CardFactory::CreateNumberCards(){
    std::vector<std::shared_ptr<Card>> numberCards;

    CreateCardsForColors(numberCards, 2);

    return numberCards;
}

void CardFactory::CreateCardsForColors(std::vector<std::shared_ptr<Card>>& numberCards, int iterations)
{
    for (size_t i = 0; i < iterations; i++)
    {
        for (int value = 0; value <= 9; ++value) {
            for (ConsoleColor color : {ConsoleColor::Red, ConsoleColor::Yellow, ConsoleColor::Green, ConsoleColor::Blue}) {
                std::shared_ptr<NumberCard> card = CreateNumberCard(value, color);
                numberCards.emplace_back(card);
            }
        }
    }
}
