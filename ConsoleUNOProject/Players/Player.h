#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../Components/Hand.h"
#include "../Components/PlayData.h"
#include "../Cards/Card.h"
#include "../Cards/Deck.h"

class Player
{
private:
	std::string name;
	std::shared_ptr<Deck> hand = std::make_shared<Deck>();
	bool hasShoutedUNO = false;
public:
	Player(std::string name);
	std::string& GetName();
	bool GetHasShoutedUNO() const;
	void SetShout(bool value);
	std::shared_ptr<Deck>& GetHand();
};

