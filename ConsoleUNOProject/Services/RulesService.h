#pragma once
#include "Service.h"
#include "ConsoleService.h"
#include <vector>
#include "../Cards/Card.h"
#include "../Cards/Deck.h"

class Rule;

class CardValidationData {
private:
    ConsoleColor color;
    std::string number;
public:
    CardValidationData(ConsoleColor color, std::string numberString);
    bool operator==(const CardValidationData other) const;
};

class RulesService : public Service
{
private:
    std::vector<std::shared_ptr<Rule>> RegisteredRules;
public:
    void Init() override;
    static std::vector<int> GetPlayableCardsIndexes(std::shared_ptr<Card> discardStackTopCard, std::vector<std::shared_ptr<Card>>& cards);
    static bool AreCardsCompatible(Card& discardStackCard, Card& otherCard);
    static bool IsValidIndexInput(int input, std::vector<int> playableCardsIndexes);
    std::vector<std::string> GetActiveRulesList();
};

