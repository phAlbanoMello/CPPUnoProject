#include "GameService.h"
#include "ConsoleService.h"
#include "../Utils/XMLReader.h"
#include "../Cards/CardFactory.h"


void GameService::Init()
{
    std::vector<NumberCard> cards = CardFactory::CreateNumberCards();

    DrawCards(cards);
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
