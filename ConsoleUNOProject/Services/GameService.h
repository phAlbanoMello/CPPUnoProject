#pragma once
#include "Service.h"
#include "../Cards/NumberCard.h"
#include "../Components/GameSettings.h"
#include "../Components/DiscardStack.h"

class GameService : public Service
{
private:
    GameSettings currentGameSettings;
    DiscardStack discardStack;
public:
    void Init() override;
    void MainMenu();
    void HandleMainMenu();
    void DrawCards(const std::vector<std::shared_ptr<Card>>& cards);
    void StartGame(GameSettings settings = {4, GameDifficulty::Medium});
    void ShuffleVector(std::vector<std::shared_ptr<Card>>& allCards);
    void SettingsMenu();
    void SetDifficultySetting(char input);
    std::string GetDifficultyString();
};

