#pragma once

enum GameDifficulty {
	Easy,
	Medium,
	Hard
};

struct GameSettings
{
public:
	int NumberOfPlayers = 4;
	GameDifficulty Difficulty = Medium;
};

