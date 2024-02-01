#include "Deck.h"

Deck::Deck()
{
}

Deck::Deck(std::vector<std::shared_ptr<Card>> cards) : cards(cards)
{
}

std::vector<std::shared_ptr<Card>>& Deck::GetCards()
{
	return cards;
}

void Deck::AddCard(std::shared_ptr<Card> card)
{
	if (card)
	{
		cards.push_back(card);
	}
}

void Deck::ReceiveCards(std::vector<std::shared_ptr<Card>> incomingCards)
{
	for (auto& Card : incomingCards)
	{
		cards.push_back(Card);
	}
}

std::shared_ptr<Card> Deck::GetNextCard() {
	std::shared_ptr<Card> card = cards.back();
	cards.pop_back();

	return card;
}

Card& Deck::CheckTopCard() {
	return *cards.back();
}