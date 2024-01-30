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
	std::vector<std::shared_ptr<Card>>& GetDeck();
	void SendCardTo(std::string cardId, Deck destinationDeck);
	void SendMultipleCardsTo(std::vector<std::string> cardsToSend, Deck destinationDeck);
	void AddCard(std::shared_ptr<Card> card);
	void ReceiveCards(std::vector<std::shared_ptr<Card>> incomingCards);
};

