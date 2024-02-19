#include "PlayerService.h"
#include "../Utils/XMLReader.h"
#include <random>

void PlayerService::Init()
{
}
void PlayerService::CreatePlayers(int numPlayers)
{
    // Path to the XML file containing character names and Stand Power descriptions
    std::string filePath = "Resources/standDescriptions.xml";

    // Load character names and Stand Power descriptions from the XMLReader
    std::unordered_map<std::string, std::string> characterStandMap;
 
    try {
        XMLReader xmlReader{ filePath };
        characterStandMap = xmlReader.GetCharacterData();
    }
    catch (const std::exception& ex) {
        std::cerr << "Error loading character names and stand descriptions" << std::endl;
        return;
    }

    // Check if there are enough character data loaded to create players
    if (numPlayers < 2)
    {
        std::cerr << "Invalid amount of players or insufficient character data" << std::endl;
        return;
    }

    // Create players using character names and Stand Power descriptions
    auto it = characterStandMap.begin();
    for (int i = 0; i < numPlayers; ++i, ++it)
    {
        // Extract character name and Stand Power description from the unordered_map
        const std::string& characterName = it->first;
        const std::string& standDescription = it->second;

        // Create player and add to players vector
        std::shared_ptr<Player> player = std::make_shared<Player>(characterName, standDescription);
        players.push_back(player);
    }
}


void PlayerService::SetSettings(GameSettings gameSettings)
{
	settings = gameSettings;
}

std::vector<std::shared_ptr<Player>>& PlayerService::GetPlayers()
{
	return players;
}

void PlayerService::DealCards(Deck& deck)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			players[i]->GetHand()->AddCard(deck.GetNextCard());
		}
	}
}

void PlayerService::ReversePlayersOrder() {
	std::reverse(players.begin(), players.end());
}

void PlayerService::ShufflePlayers() {
	std::random_device rd;
	std::default_random_engine rng(rd());
	std::shuffle(players.begin(), players.end(), rng);
}