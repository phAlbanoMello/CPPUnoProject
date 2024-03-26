#pragma once
#include <string>
#include <vector>
#include "../Players/Player.h"
#include "../Services/GameStateService.h"

class GameStateService;

class Rule {
private:
    std::string _ruleID;
protected:
    bool _isActive = false;
    GameStateService& _gameStateService;
    std::vector<std::shared_ptr<Player>> _targets = {};
public:
    Rule(GameStateService& gsService, std::string ruleId) : _gameStateService(gsService), _ruleID(ruleId){}
    virtual void SetTargets(std::vector<std::shared_ptr<Player>> targets);
    virtual std::vector<std::shared_ptr<Player>>& GetTargets();
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    virtual bool isActive() const = 0;
    std::string GetRuleID();
};


