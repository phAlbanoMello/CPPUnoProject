#include "SpecialCard.h"
#include "CardFactory.h"

SpecialCard::SpecialCard(GameStateService& gsService, CardArt cardArt, std::string cardValue) : Card(cardArt, cardValue), _gsService(gsService)
{
}

void SpecialCard::PrintCardData()
{
	ConsoleService::Print(CardFactory::GetColorName(cardArt.color));
	ConsoleService::Print(cardValue);
}

void SpecialCard::DrawArt() const
{
	for (const auto& frame : cardArt.cardArtStrings) {
		ConsoleService::PrintWithColor(*frame, cardArt.color);
	}
}

CardArt SpecialCard::GetCardArt() const
{
	return cardArt;
}

std::string SpecialCard::GetCardValue() const
{
	return cardValue;
}

void SpecialCard::Activate()
{
}

void SpecialCard::Revert()
{
}
