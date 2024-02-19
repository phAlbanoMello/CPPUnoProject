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
	std::string _name;
	std::shared_ptr<Deck> _hand = std::make_shared<Deck>();
	bool _hasShoutedUNO = false;
	bool _hasOneCard = false;
	bool _isPlayerCharacter = false;
	std::string _standDescription;
public:
	Player();
	Player(std::string name, std::string standDescription);
	std::string& GetName();
	bool GetHasShoutedUNO() const;
	void SetShout(bool value);
	void SetHasOneCard(bool value);
	void SelectAsPlayerCharacter();
	bool GetHasOneCard() const;
	bool GetIsPlayerCharacter();
	std::string GetStandDescription();
	std::shared_ptr<Deck>& GetHand();
};

