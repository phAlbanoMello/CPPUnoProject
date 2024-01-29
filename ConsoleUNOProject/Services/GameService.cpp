#include "GameService.h"
#include "ConsoleService.h"
#include "../Utils/XMLReader.h"
#include "../Cards/CardFactory.h"
#include "InputService.h"
#include <conio.h>
#include <iostream>


const char startGameKeyString = 'S';
const char customSettingsString = 'C';
const char exitString = 'E';

void PrintKeyName(const char* keyName) {
    std::cout << "Arrow Key Pressed: " << keyName << std::endl;
}

void GameService::Init()
{
    currentGameSettings = { 3, Medium };//Default

    MainMenu();
}

void GameService::MainMenu()
{
    ConsoleService::PrintWithColor("Welcome to UNO", ConsoleColor::Blue);
    ConsoleService::PrintDivisor();

    ConsoleService::PrintWithColor("Start Game (Default Settings) [" + std::string(1, startGameKeyString) + "]", ConsoleColor::Yellow);
    ConsoleService::Print("Custom Settings [" + std::string(1, customSettingsString) + "]");
    ConsoleService::Print("Exit [" + std::string(1, exitString) + "]");

    ConsoleService::PrintDivisor();

    HandleMainMenu();
}

void GameService::HandleMainMenu()
{
    switch (std::toupper(InputService::GetPlayerInput()))
    {
    case startGameKeyString:
        ConsoleService::Print("StartGame Selected");
        GameService::StartGame();
        break;
    case customSettingsString:
        ConsoleService::Print("Custom Settings Selected");
        //TODO: Ask for custom settings
        GameService::AskForSettings();
        break;
    case exitString:
        ConsoleService::Print("Exit selected");
        break;
    default:
        break;
    }
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

void GameService::StartGame(GameSettings settings) {
    currentGameSettings = settings;
}

void GameService::AskForSettings() {
    ConsoleService::Clear();
    ConsoleService::PrintWithColor("Custom Settings", ConsoleColor::Blue);
    ConsoleService::PrintDivisor(2);
    ConsoleService::PrintWithColor("Press the corresponding key to edit the value", ConsoleColor::Yellow);
    ConsoleService::PrintDivisor(2);
    ConsoleService::Print("Number of Players (Besides You) : " + std::to_string(currentGameSettings.NumberOfPlayers) + " [N]");
    ConsoleService::Print("Difficulty : " + GetDifficultyString() + " [D]");
    ConsoleService::PrintDivisor();
    ConsoleService::Print("(Press Enter to Return)");

    char input = InputService::GetPlayerInput();
    switch (std::toupper(input))
    {
    case 'N':
        ConsoleService::PrintDivisor();
        ConsoleService::Print("Enter the total amount of players (min 2 max 10):");
        //TODO:Get players amount
        break;
    case 'D':
        ConsoleService::PrintDivisor();
        ConsoleService::Print("Select a Difficulty [E]Easy, [M]Medium, [H]Hard");
        //TODO:Get player input and set difficulty
        break;
    case '\n':
        ReturnToMenu();
        break;
    default:
        break;
    }
}

void GameService::ReturnToMenu() {
    ConsoleService::Clear();
    MainMenu();
}

std::string GameService::GetDifficultyString() {
    switch (currentGameSettings.Difficulty)
    {
    case GameDifficulty::Easy:
        return "Easy";
        break;
    case GameDifficulty::Medium:
        return "Medium";
        break;
    case GameDifficulty::Hard:
        return "Hard";
        break;
    default:
        break;
    }
}