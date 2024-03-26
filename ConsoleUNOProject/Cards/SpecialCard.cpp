#include "SpecialCard.h"
#include "CardFactory.h"

SpecialCard::SpecialCard(GameStateService& gsService, CardArt cardArt, std::string cardValue) : Card(cardArt, cardValue), _gsService(gsService)
{
}

void SpecialCard::PrintCardData()
{
	ConsoleService::Print(CardFactory::GetColorName(_cardArt.color));
	ConsoleService::Print(_cardValue);
}

void SpecialCard::DrawArt() const
{
	for (const auto& frame : _cardArt.cardArtStrings) {
		ConsoleService::PrintWithColor(*frame, _cardArt.color);
	}
}

CardArt SpecialCard::GetCardArt() const
{
	return _cardArt;
}

std::string SpecialCard::GetCardValue() const
{
	return _cardValue;
}

void SpecialCard::Activate()
{
}

void SpecialCard::Revert()
{
}
