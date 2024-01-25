#include "CardFactory.h"

std::shared_ptr<std::string> CreateFrameString(const std::string& frame) {
    std::shared_ptr<std::string> frameString = std::make_shared<std::string>(frame);
    return frameString;
}

CardArt CardFactory::MakeNumberCardArt(int number, ConsoleColor color) {
    CardArt cardArt;

    std::string borderFrame = "|=========|";
    std::string bodyFrame = "|         |";
    std::string valueFrame = "|    {0}    |";

    size_t valuePos = valueFrame.find("{0}");
    valueFrame.replace(valuePos, 3, std::to_string(number));

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
        return "   red   ";
    case ConsoleColor::Yellow:
        return " yellow  ";
    case ConsoleColor::Black:
        return "  black  ";
    case ConsoleColor::Blue:
        return "   blue  ";
    case ConsoleColor::Green:
        return "  green  ";
    default:
        return "         ";
    }
}