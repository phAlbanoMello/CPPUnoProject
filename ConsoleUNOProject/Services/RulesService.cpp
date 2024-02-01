#include "RulesService.h"

void RulesService::Init()
{
}
CardValidationData::CardValidationData(ConsoleColor color, std::string numberString) : color(color), number(numberString)
{
}

std::vector<int> RulesService::GetPlayableCardsIndexes(std::shared_ptr<Card> discardStackTopCard, std::vector<std::shared_ptr<Card>>& cards)
{
	std::vector<int> validCardIndexes = {};

	CardValidationData dStackCardData = CardValidationData{ discardStackTopCard->GetColor(), discardStackTopCard->GetCardValue() };

	for (size_t i = 0; i < cards.size(); i++)
	{
		CardValidationData cardVData = CardValidationData{ cards[i]->GetColor(), cards[i]->GetCardValue() };
		if (cardVData == dStackCardData)
		{
			validCardIndexes.push_back(i);
		}
	}

	return validCardIndexes;
}

bool RulesService::AreCardsCompatible(Card& discardStackCard, Card& otherCard)
{
	CardValidationData cardAVData = CardValidationData{ discardStackCard.GetColor(), discardStackCard.GetCardValue() };
	CardValidationData cardBVData = CardValidationData{ otherCard.GetColor(), otherCard.GetCardValue() };

	//TODO: turn this into a overriden operator at Card  
	return cardAVData == cardBVData;
}

bool RulesService::IsValidIndexInput(int input, std::vector<int> playableCardsIndexes)
{
	for (size_t i = 0; i < playableCardsIndexes.size(); i++)
	{
		if (input == playableCardsIndexes[i])
		{
			return true;
		}
	}
	return false;
}


bool CardValidationData::operator==(const CardValidationData other) const
{
	if (color == other.color || number == other.number)
	{
		return true;
	}
	return false;
}
