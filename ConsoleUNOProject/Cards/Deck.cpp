#include "Deck.h"

std::vector<std::shared_ptr<Card>>& Deck::GetDeck()
{
	return cards;
}

void Deck::SendCardTo(std::string cardId, Deck destinationDeck)
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		if (cards[i]->GetId() == cardId)
		{
			destinationDeck.AddCard(std::move(cards[i]));
			cards.erase(cards.begin() + i);
			break;
		}
	}
}
void Deck::SendMultipleCardsTo(std::vector<std::string> cardsToSend, Deck destinationDeck) {
	for (size_t i = 0; i < cards.size(); i++)
	{
		std::string cardId = cards[i]->GetId();
		auto iterator = std::find(cardsToSend.begin(), cardsToSend.end(), cardId);

		if (iterator != cardsToSend.end())
		{
			destinationDeck.AddCard(std::move(cards[i]));
			cards.erase(cards.begin() + i);
		}
	}
}

void Deck::AddCard(std::shared_ptr<Card> card)
{
	cards.push_back(card);
}

void Deck::ReceiveCards(std::vector<std::shared_ptr<Card>> incomingCards)
{
	for (auto& Card : incomingCards)
	{
		cards.push_back(Card);
	}
}
