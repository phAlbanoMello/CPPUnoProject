#pragma once
#include <string>

class GameStateService;

class Rule {
private:
    GameStateService& gameStateService;
    std::string _ruleID;
public:
    Rule(GameStateService& gsService, std::string ruleId) : gameStateService(gsService), _ruleID(ruleId){}
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual bool isActive() const = 0;
    std::string GetRuleID();
};


