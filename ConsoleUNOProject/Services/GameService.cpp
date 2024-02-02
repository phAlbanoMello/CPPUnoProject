#include <conio.h>
#include <iostream>
#include "GameService.h"
#include "ConsoleService.h"
#include "InputService.h"
#include "../Utils/XMLReader.h"
#include "../Cards/CardFactory.h"
#include "PlayerService.h"
#include "RulesService.h"
#include <chrono>
#include <random>
#include <sstream>

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
	ConsoleService::Clear();
	currentGameState = GameState::Menu;

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
		GameService::StartGame(currentGameSettings);
		break;
	case customSettingsString:
		ConsoleService::Print("Custom Settings Selected");
		GameService::SettingsMenu();
		break;
	case exitString:
		ConsoleService::Print("Exit selected");
		break;
	default:
		break;
	}
}

void GameService::DrawCards(const std::vector<std::shared_ptr<Card>>& cards) {
	if (cards.empty()) {
		return;
	}

	size_t frameCount = cards[0]->GetCardArt().cardArtStrings.size();

	for (size_t frameIndex = 0; frameIndex < frameCount; ++frameIndex) {
		for (const auto& card : cards) {
			const auto& cardArt = card->GetCardArt();

			if (frameIndex < cardArt.cardArtStrings.size()) {
				ConsoleService::PrintWithColor(*cardArt.cardArtStrings[frameIndex], cardArt.color, false);
				std::cout << "   ";
			}
		}

		std::cout << std::endl;
	}
}


void GameService::StartGame(GameSettings settings) {
	ConsoleService::Clear();
	currentGameState = GameState::Playing;

	// Setup players and cards -----------------------------------------------------------------
	currentGameSettings = settings;
	PlayerService playerService = PlayerService{};
	playerService.CreatePlayers(currentGameSettings.NumberOfPlayers);
	std::vector<std::shared_ptr<Card>> allCards = CardFactory::CreateNumberCards();

	//Shuffle and Deal cards -------------------------------------------------------------------
	ShuffleVector(allCards);
	Deck allCardsDeck = Deck{ allCards };
	playerService.DealCards(allCardsDeck);

	//Set first card of Discard Stack ----------------------------------------------------------
	discardStack.AddCard(allCardsDeck.GetNextCard());
	//Start Game Loop
	bool playingGame = true;
	int currentPlayerIndex = 0;
	while (playingGame)
	{
		ConsoleService::Clear();
		ConsoleService::PrintDivisor();
		std::vector<std::shared_ptr<Player>> players = playerService.GetPlayers();
		Card& currentCardOnTopOfDiscardStack = discardStack.CheckTopCard();
		std::shared_ptr<Player> player = playerService.GetPlayers()[currentPlayerIndex];
		Deck& currentPlayerHand = *player->GetHand();
	
		PrintPlayersStats(players, currentPlayerIndex);
		PrintDiscardStackTopCard(currentCardOnTopOfDiscardStack);
		PrintCurrentPlayerHand(player, currentPlayerHand);
		
		HandleGameOver();

		if (HasPlayableCards(currentCardOnTopOfDiscardStack, player))
		{
			PrintPlayerInputInterface(currentCardOnTopOfDiscardStack, player);
			int fixedCardIndexInput = InputService::GetPlayerInputOfType<int>() - 1;
			
			std::vector<int> playableCardsIndexes = RulesService::GetPlayableCardsIndexes(std::make_shared<Card>(currentCardOnTopOfDiscardStack), currentPlayerHand.GetCards());
			if (!RulesService::IsValidIndexInput(fixedCardIndexInput, playableCardsIndexes))
			{
				PrintInvalidInputMessage();
				_getch();
				continue;
			}
			if (RulesService::AreCardsCompatible(currentCardOnTopOfDiscardStack, *currentPlayerHand.GetCards()[fixedCardIndexInput]))
			{
				auto& currentPlayerCards = currentPlayerHand.GetCards();
				discardStack.AddCard(currentPlayerCards[fixedCardIndexInput]);

				currentPlayerCards.erase(currentPlayerCards.begin() + fixedCardIndexInput);
				currentPlayerIndex = currentPlayerIndex < players.size() - 1 ? currentPlayerIndex += 1 : 0;

				if (currentPlayerCards.size() == 1)
				{
					player->SetHasOneCard(true);
					ConsoleService::PrintWithColor("You have one card! End your turn by shouting UNO! (Press [U] instead of [Enter])", ConsoleColor::Green);
					ConsoleService::PrintDivisor();
					CheckUNOShout(player);
				}
				else
				{
					ConsoleService::PrintDivisor();
					ConsoleService::Print("Confirm to finish your turn");
					_getch();
					continue;
				}
				//TODO:Check turns stats with RulesService
			}
			else {
				PrintInvalidInputMessage();
				_getch();
				continue;
			}
		}
		else {
			ConsoleService::Print(player->GetName() + " has no cards that can be placed. Press Enter to end the turn and buy a card.");
			ConsoleService::PrintDivisor();
			currentPlayerHand.AddCard(allCardsDeck.GetNextCard());
			currentPlayerIndex = currentPlayerIndex < players.size() - 1 ? currentPlayerIndex += 1 : 0;
			ConsoleService::PrintDivisor();
			ConsoleService::Print("Confirm to finish your turn");
			_getch();
			continue;
		}
	}
	_getch();
}

void GameService::PrintCurrentPlayerHand(std::shared_ptr<Player>& player, Deck& currentPlayerHand)
{
	ConsoleService::PrintDivisor();
	ConsoleService::Print(player->GetName() + " Hand : ");
	ConsoleService::PrintDivisor();
	DrawCards(currentPlayerHand.GetCards());
	ConsoleService::PrintDivisor();
}

void GameService::PrintDiscardStackTopCard(Card& currentCardOnTopOfDiscardStack)
{
	ConsoleService::PrintDivisor();
	ConsoleService::Print("Discard Stack : ");
	ConsoleService::PrintDivisor();
	currentCardOnTopOfDiscardStack.DrawArt();
}

void GameService::PrintPlayerInputInterface(Card& currentCardOnTopOfDiscardStack, std::shared_ptr<Player>& player)
{
	ConsoleService::Print("Select a card by it's order from left to right (Press the corresponding number)");
	ConsoleService::Print(GenerateIndexMenuString(currentCardOnTopOfDiscardStack, player));
	ConsoleService::PrintDivisor();
}

void GameService::HandleGameOver()
{
	if (currentGameState == GameState::GameOver)
	{
		ConsoleService::PrintWithColor("|------- Game Over -------|", ConsoleColor::Green);
		ConsoleService::PrintWithColor("|-----Winner is : " + winner->GetName() + "------|", ConsoleColor::Green);
		ConsoleService::PrintDivisor();
		ConsoleService::Print("Press Enter to return to Menu");
		_getch();
		MainMenu();
	}
}

void GameService::CheckUNOShout(std::shared_ptr<Player>& player) {
	if (player->GetHasOneCard()) {
		ConsoleService::PrintDivisor();
		ConsoleService::Print("Confirm to finish your turn");

		char input = _getch();
		player->SetShout(std::toupper(input) == 'U');
	}
}

void GameService::PrintInvalidInputMessage()
{
	ConsoleService::PrintDivisor();
	ConsoleService::PrintWithColor("Invalid input!", ConsoleColor::Red);
	ConsoleService::PrintDivisor();
}

void GameService::PrintPlayersStats(std::vector<std::shared_ptr<Player>>& players, int currentPlayerIndex)
{
	for (size_t i = 0; i < players.size(); i++)
	{
		std::string unoShout = players[i]->GetHasOneCard() && players[i]->GetHasShoutedUNO() ? " <- UNO!!!! " : "";
		if (players[i]->GetHand()->GetCards().size() == 0)
		{
			unoShout = " <- WINNER ";
			winner = players[i];
			currentGameState = GameState::GameOver;
		}
		std::stringstream playerData;
		if (i == currentPlayerIndex)
		{
			playerData << " " << players[i]->GetName() << " - Hand : " << players[i]->GetHand()->GetCards().size() << " <- Turn" << unoShout;
			ConsoleService::PrintWithColor(playerData.str(), ConsoleColor::Yellow);
		}
		else {
			playerData << players[i]->GetName() << " - Hand : " << players[i]->GetHand()->GetCards().size() << unoShout;
			ConsoleService::Print(playerData.str());
		}
	}
}

bool GameService::HasPlayableCards(Card& dStackTopCard, std::shared_ptr<Player> player) {
	std::vector<int> playableCardsIndexes = RulesService::GetPlayableCardsIndexes(
		std::make_shared<Card>(dStackTopCard),
		player->GetHand()->GetCards()
	);

	return !playableCardsIndexes.empty();
}

std::string GameService::GenerateIndexMenuString(Card& dStackTopCard, std::shared_ptr<Player> player) {
	std::stringstream indexMenu;

	char orderSymbol = 248;
	std::vector<int> playableCardsIndexes = RulesService::GetPlayableCardsIndexes(
		std::make_shared<Card>(dStackTopCard),
		player->GetHand()->GetCards()
	);

	for (size_t i = 0; i < playableCardsIndexes.size(); i++) {
		indexMenu << "[" << playableCardsIndexes[i] + 1 << orderSymbol << "]";
	}

	return indexMenu.str();
}


void GameService::ShuffleVector(std::vector<std::shared_ptr<Card>>& allCards)
{
	const unsigned int seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
	auto rng = std::default_random_engine{ seed };
	std::shuffle(allCards.begin(), allCards.end(), rng);
}

void GameService::SettingsMenu() {
	ConsoleService::Clear();
	currentGameState = GameState::Settings;

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
		int input;
		std::cin >> input;
		currentGameSettings.NumberOfPlayers = input;
		SettingsMenu();
		break;
	case 'D':
		ConsoleService::PrintDivisor();
		ConsoleService::Print("Select a Difficulty [E]Easy, [M]Medium, [H]Hard");
		SetDifficultySetting(_getch());
		break;
	case '\n':
		MainMenu();
		break;
	default:
		break;
	}
}

void GameService::SetDifficultySetting(char input)
{
	switch (std::toupper(input))
	{
	case 'E':
		currentGameSettings.Difficulty = Easy;
		break;
	case 'M':
		currentGameSettings.Difficulty = Medium;
		break;
	case 'H':
		currentGameSettings.Difficulty = Hard;
		break;
	default:
		break;
	}
	SettingsMenu();
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