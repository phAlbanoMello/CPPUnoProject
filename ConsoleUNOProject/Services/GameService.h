#pragma once
#include<vector>
#include<string>
#include<memory>
#include "Service.h"
#include "../Cards/NumberCard.h"
#include "../Components/GameSettings.h"
#include "../Components/DiscardStack.h"
#include "../Players/Player.h"

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
    void PrintInvalidInputMessage();
    void PrintPlayersStats(std::vector<std::shared_ptr<Player>>& players, int currentPlayerIndex);
    bool HasPlayableCards(Card& dStackTopCard, std::shared_ptr<Player> player);
    void ShuffleVector(std::vector<std::shared_ptr<Card>>& allCards);
    void SettingsMenu();
    void SetDifficultySetting(char input);
    
    std::string GenerateIndexMenuString(Card& dStackTopCard, std::shared_ptr<Player> player);
    std::string GetDifficultyString();
};

