#pragma once
#include "Service.h"
class PlayerService : public Service
{
public:
    void Init() override {
        std::cout << "Initializing PlayerService" << std::endl;
    }

    void Test() {
        std::cout << "Test Okay" << std::endl;
    }
};

