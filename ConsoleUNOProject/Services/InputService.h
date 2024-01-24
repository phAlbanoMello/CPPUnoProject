#pragma once
#include "Service.h"
class InputService : public Service
{
    void Init() override {
        std::cout << "Initializing InputService" << std::endl;
    }
};

