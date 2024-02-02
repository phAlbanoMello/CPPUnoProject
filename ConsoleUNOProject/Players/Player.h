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
	bool hasOneCard = false;
public:
	Player();
	Player(std::string name);
	std::string& GetName();
	bool GetHasShoutedUNO() const;
	void SetShout(bool value);
	void SetHasOneCard(bool value);
	bool GetHasOneCard() const;
	std::shared_ptr<Deck>& GetHand();
};

