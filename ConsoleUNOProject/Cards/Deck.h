#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../Cards/Card.h"

class Deck
{
private:
	std::vector<std::shared_ptr<Card>> cards = {};
public:
	Deck();
	Deck(std::vector<std::shared_ptr<Card>> cards);
	std::vector<std::shared_ptr<Card>>& GetDeck();
	void AddCard(std::shared_ptr<Card> card);
	void ReceiveCards(std::vector<std::shared_ptr<Card>> incomingCards);
	std::shared_ptr<Card> GetNextCard();
	Card& CheckTopCard();
};

