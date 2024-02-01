#pragma once
#include "../Services/ConsoleService.h"
#include <functional>
#include <memory>
#include <vector>

struct CardArt {
	std::vector<std::shared_ptr<std::string>> cardArtStrings;
	ConsoleColor color;
};

class Card
{
protected:
	CardArt cardArt;
	std::string cardValue;
	std::shared_ptr<std::function<void()>> action;
public:
	Card(CardArt cardArt, std::string value);
	ConsoleColor GetColor() const;
	void SetAction(std::function<void()> cardAction);
	void InvokeAction();
	virtual void PrintCardData();
	virtual void DrawArt() const;
	virtual CardArt GetCardArt();
	virtual std::string GetCardValue() const;
};

