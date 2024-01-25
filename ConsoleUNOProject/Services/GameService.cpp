#include "GameService.h"
#include "ConsoleService.h"


void GameService::Init()
{
    NumberCard oneBlue = NumberCard{ 3, ConsoleColor::Blue };
    NumberCard twoRed = NumberCard{ 2, ConsoleColor::Red };
    NumberCard threeYellow = NumberCard{ 5, ConsoleColor::Yellow };
    NumberCard dStackCard = NumberCard{ 6, ConsoleColor::Red };
    std::vector<NumberCard> cards = { oneBlue, twoRed, threeYellow };

    ConsoleService::Print("Your hand");
	DrawCards(cards);
    ConsoleService::Print("Discard stack current card: ");
    dStackCard.DrawArt();
}

void GameService::DrawCards(const std::vector<NumberCard>& cards) {
    size_t frameCount = cards[0].GetCardArt().cardArtStrings.size();

    for (size_t frameIndex = 0; frameIndex < frameCount; ++frameIndex) {
        for (const auto& card : cards) {
            ConsoleService::PrintWithColor(*card.GetCardArt().cardArtStrings[frameIndex], card.GetCardArt().color, false);
            std::cout << "   ";
        }

        std::cout << std::endl;
    }
}