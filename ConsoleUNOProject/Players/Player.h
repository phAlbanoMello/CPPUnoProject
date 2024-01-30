#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../Components/Hand.h"
#include "../Components/PlayData.h"
#include "../Cards/Card.h"

class Player
{
private:
	std::string name;
	std::shared_ptr<Hand> hand = std::make_shared<Hand>();
	bool hasShoutedUNO;
public:
	Player(std::string name);
	std::string& GetName();
	Card PlayCard(std::string id);
	bool GetHasShoutedUNO() const;
	void SetShout(bool value);
	std::shared_ptr<Hand>& GetHand();
};

