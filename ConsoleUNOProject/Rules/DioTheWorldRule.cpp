#include "DioTheWorldRule.h"

DioTheWorldRule::DioTheWorldRule(GameStateService& gsService, std::string ruleId) : Rule(gsService, ruleId)
{
}

void DioTheWorldRule::activate()
{
	_isActive = true;

}

void DioTheWorldRule::deactivate()
{
	_isActive = false;
}

bool DioTheWorldRule::isActive() const
{
	return _isActive;
}
