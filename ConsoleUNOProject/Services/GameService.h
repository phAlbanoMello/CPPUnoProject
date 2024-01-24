#pragma once
#include "Service.h"
class GameService : public Service
{
    void Init() override {
        std::cout << "Initializing GameService" << std::endl;
    }
};

