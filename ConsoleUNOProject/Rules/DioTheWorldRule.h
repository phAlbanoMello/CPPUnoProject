#pragma once
#include "Rule.h"

class DioTheWorldRule : public Rule
{
public:
	DioTheWorldRule(GameStateService& gsService, std::string ruleId);
	// Herdado por meio de Rule
	void activate() override;
	void deactivate() override;
	bool isActive() const override;
};

