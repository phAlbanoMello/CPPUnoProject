#pragma once
#include "Service.h"
#include "ConsoleService.h"

struct CardValidationData {
    ConsoleColor color;
    int number;
};

class RulesService : public Service
{
private:
    CardValidationData cardVData;

public:
    void Init() override;
};

