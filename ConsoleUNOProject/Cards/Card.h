#pragma once
#include "../Services/ConsoleService.h"
#include <functional>
#include <memory>
#include <vector>
#include "../Components/Turn.h"

class GameStateService;

struct CardArt {
	std::vector<std::shared_ptr<std::string>> cardArtStrings;
	ConsoleColor color;
};

class Card
{
protected:
	CardArt _cardArt; 
	std::string _cardValue;
	std::shared_ptr<std::function<void(GameStateService&)>> _action;
public:
	Card(CardArt cardArt, std::string value);
	ConsoleColor GetColor() const;
	void SetAction(std::function<void(GameStateService&)> cardAction);
	void InvokeAction();
	virtual void PrintCardData();
	virtual void DrawArt() const;
	virtual CardArt GetCardArt();
	virtual std::string GetCardValue() const;
};

