#pragma once
#include<vector>
#include<string>
#include<memory>
#include "Service.h"
#include "../Cards/NumberCard.h"
#include "../Components/GameSettings.h"
#include "../Components/DiscardStack.h"
#include "../Players/Player.h"
#include "../Services/RulesService.h"
#include "../Services/PlayerService.h"
#include "../Services/GameStateService.h"

enum class GameState {
    Menu,
    Settings,
    Playing,
    GameOver,
    Eve
};


class GameService : public Service
{
private:
    std::shared_ptr<RulesService> _rulesService;
    std::shared_ptr<PlayerService> _playerService;

    const std::string SETTINGS_FILE_PATH = "Resources/settings.xml";
    GameSettings currentGameSettings;
    DiscardStack discardStack;
    GameState currentGameState;
    std::shared_ptr<Player> winner = std::make_shared<Player>();
public:
    void Init() override;
    void SetRulesService(std::shared_ptr<RulesService> rulesService);
    void SetPlayerServices(std::shared_ptr<PlayerService> playerService);
    void MainMenu();
    std::shared_ptr<Player> CharacterSelection();
    void HandleMainMenu();
    void DrawCards(const std::vector<std::shared_ptr<Card>>& cards);
    void StartGame(GameSettings settings = {4});
    void UpdatePlayerIndex(GameStateService& gameState);
    void CheckForGameOver(bool& playingGame);
    void PrintDrawPileAmount(Deck& drawPile);
    void PrintCurrentPlayerHand(std::shared_ptr<Player>& player, Deck& currentPlayerHand);
    void PrintDiscardStackTopCard(Card& currentCardOnTopOfDiscardStack);
    void PrintPlayerInputInterface(Card& currentCardOnTopOfDiscardStack, std::shared_ptr<Player>& player);
    void HandleGameOver();
    void PrintInvalidInputMessage();
    void PrintPlayersStats(std::vector<std::shared_ptr<Player>>& players, int currentPlayerIndex);
    bool HasPlayableCards(Card& dStackTopCard, std::shared_ptr<Player> player);
    void ShuffleCards(std::vector<std::shared_ptr<Card>>& allCards);
    void SettingsMenu();
    void PrintConfirmationPromptWithShoutOption(std::shared_ptr<Player>& player);
    void SaveSettings();
    void LoadSettings();

    std::string GenerateIndexMenuString(Card& dStackTopCard, std::shared_ptr<Player> player);
};

