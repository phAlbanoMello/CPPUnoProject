#pragma once
#include "../Services/ConsoleService.h"
#include <functional>
#include <memory>
class Card
{
private:
	std::string id;
	ConsoleColor color = ConsoleColor::Default;
	std::shared_ptr<std::function<void()>> action;
public:
	std::string GetId();
	ConsoleColor GetColor();
	void SetAction(std::function<void()> cardAction);
};

