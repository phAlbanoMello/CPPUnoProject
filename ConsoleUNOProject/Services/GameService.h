#pragma once
#include "Service.h"
#include "../Cards/NumberCard.h"
#include "../GameSettings.h"

class GameService : public Service
{
private:
    GameSettings currentGameSettings;
public:
    void Init() override;
    void MainMenu();
    void HandleMainMenu();
    void DrawCards(const std::vector<NumberCard>& cards);
    void StartGame(GameSettings settings = {4, GameDifficulty::Medium});
    void AskForSettings();
    void ReturnToMenu();
    std::string GetDifficultyString();
};

