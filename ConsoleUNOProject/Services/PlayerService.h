#pragma once
#include "Service.h"
#include "../Components/GameSettings.h"
#include <vector>
#include <memory>
#include "../Players/Player.h"

class PlayerService : public Service
{
private:
	GameSettings settings;
	std::vector<std::shared_ptr<Player>> players = {};
public:
	void Init() override;
	void CreatePlayers(int amount);
	void SetSettings(GameSettings settings);
	std::vector<std::shared_ptr<Player>>& GetPlayers();
};

