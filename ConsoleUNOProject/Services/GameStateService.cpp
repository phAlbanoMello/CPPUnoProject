#include "GameStateService.h"

GameStateService::GameStateService(std::shared_ptr<PlayerService> playerService, Deck& discardStack, std::shared_ptr<RulesService> rulesService)
	: _matchPlayers(playerService->GetPlayers()),
	_stateData{ 0, 0, 1, discardStack.CheckTopCard().GetColor(), 
	GameFlowDirection::Clockwise },
	_activeRulesIds(rulesService->GetActiveRulesList()){}

void GameStateService::UpdateCurrentPlayerIndex(int skipAmount) {
	if (skipAmount == 0) {
		_stateData.PreviousPlayerIndex = _stateData.PlayerIndex;
		_stateData.PlayerIndex = (_stateData.PlayerIndex + 1) % _matchPlayers.size();
		_stateData.NextPlayerIndex = (_stateData.PlayerIndex + 1) % _matchPlayers.size();
	}
	else {
		_stateData.PreviousPlayerIndex = _stateData.PlayerIndex;
		_stateData.PlayerIndex = (_stateData.PlayerIndex + skipAmount) % _matchPlayers.size();
		_stateData.NextPlayerIndex = (_stateData.PlayerIndex + 1) % _matchPlayers.size();
	}
}

void GameStateService::ChangeGameColor(ConsoleColor color)
{
	_stateData.GameColor = color;
}

void GameStateService::ChangeFlowDirection(GameFlowDirection flowDirection)
{
	_stateData.FlowDirection = flowDirection;
}

BaseStateData GameStateService::GetStateData()
{
	return _stateData;
}

std::string GameStateService::ConsoleColorToString(ConsoleColor color) {
	switch (color)
	{
	case ConsoleColor::Default:
		return "None";
	case ConsoleColor::Wild:
		return "Wild";
	case ConsoleColor::Blue:
		return "Blue";
	case ConsoleColor::Green:
		return "Green";
	case ConsoleColor::Red:
		return "Red";
	case ConsoleColor::Yellow:
		return "Yellow";
	default:
		break;
	}
}

std::string GameStateService::GameFlowDirectionToString(GameFlowDirection direction) {
	switch (direction)
	{
	case GameFlowDirection::Clockwise:
		return "Clockwise";
	case GameFlowDirection::Counterclockwise:
		return "Counterclockwise";
	default:
		break;
	}
}

void GameStateService::PrintBaseStateData() {
	ConsoleService::PrintDivisor();
	std::cout << "Previous Player Index: " << _stateData.PreviousPlayerIndex << std::endl;
	std::cout << "Player Index: " << _stateData.PlayerIndex << std::endl;
	std::cout << "Next Player Index: " << _stateData.NextPlayerIndex << std::endl;
	std::cout << "Game Color: " << ConsoleColorToString(_stateData.GameColor) << std::endl;
	std::cout << "Flow Direction: " << GameFlowDirectionToString(_stateData.FlowDirection) << std::endl;
}