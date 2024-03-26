#include "Rule.h"

void Rule::SetTargets(std::vector<std::shared_ptr<Player>> targets)
{
    _targets = targets;
}

std::vector<std::shared_ptr<Player>>& Rule::GetTargets()
{
    return _targets;
}

std::string Rule::GetRuleID()
{
    return _ruleID;
}
