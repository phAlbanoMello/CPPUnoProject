#pragma once
#include <vector>
#include "../Players/Player.h"
#include "../Rules/Rule.h"
#include "../Services/PlayerService.h"
#include "RulesService.h"

enum class GameFlowDirection {
	Clockwise,
	Counterclockwise
};

struct BaseStateData {
	std::size_t PreviousPlayerIndex;
	std::size_t PlayerIndex;
	std::size_t NextPlayerIndex;
	ConsoleColor GameColor;
	GameFlowDirection FlowDirection;
};

class GameStateService : public Service
{
private:
	std::vector<std::shared_ptr<Player>>& _matchPlayers;
	BaseStateData _stateData;
	std::vector<std::string> _activeRulesIds;

	Deck& _discardStack;
	Deck& _drawPile;

	std::string ConsoleColorToString(ConsoleColor color);
	std::string GameFlowDirectionToString(GameFlowDirection direction);
public:
	GameStateService(std::shared_ptr<PlayerService> playerService, Deck& discardStack, Deck& drawPile, std::shared_ptr<RulesService> rulesService);
	void UpdateCurrentPlayerIndex(int skipAmount = 0);
	void ChangeGameColor(ConsoleColor color);
	void ChangeFlowDirection(GameFlowDirection flowDirection);
	void PrintBaseStateData();
	BaseStateData GetStateData();

	inline Deck& GetDiscardStack() { return _discardStack; };
	inline Deck& GetDrawPile() { return _drawPile; };
};

