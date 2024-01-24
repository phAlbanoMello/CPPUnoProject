#pragma once
#include "Service.h"

class RulesService : public Service
{
    void Init() override {
        std::cout << "Initializing RulesService" << std::endl;
    }
};

