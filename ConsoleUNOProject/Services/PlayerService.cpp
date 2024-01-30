#include "PlayerService.h"
#include "../Utils/XMLReader.h"

void PlayerService::Init()
{
}
void PlayerService::CreatePlayers(int amount)
{
	std::string filePath = "../Resources/characterNames.xml";
	std::vector<std::string> characterNames = {};
	
	try {
		characterNames = XMLReader{ filePath }.getCharacterNames();
	}
	catch(const std::exception& ex){
		std::cerr << "Error loading character names" << std::endl;
	}

	if (amount >= 2 && characterNames.size() >= amount)
	{
		for (size_t i = 0; i < amount; i++)
		{
			players.push_back(std::make_shared<Player>(characterNames[i]));
		}
	}
	else
	{
		std::cerr << "Invalid Amount of Players" << std::endl;
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
