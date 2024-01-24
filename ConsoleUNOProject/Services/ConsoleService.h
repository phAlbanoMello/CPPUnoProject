#pragma once
#include "Service.h"
class ConsoleService : public Service
{
    void Init() override {
        std::cout << "Initializing GameService" << std::endl;
    }
};

