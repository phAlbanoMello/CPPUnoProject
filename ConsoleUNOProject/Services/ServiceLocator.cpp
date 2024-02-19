#include <vector>
#include <memory>

#include "ServiceLocator.h"
#include "Service.h"
#include "ConsoleService.h"
#include "GameService.h"
#include "InputService.h"
#include "RulesService.h"
#include "PlayerService.h"

std::vector<std::shared_ptr<Service>> ServiceLocator::serviceInstances;

void ServiceLocator::RegisterService(std::shared_ptr<Service> service)
{
    serviceInstances.push_back(service);
}

void ServiceLocator::Init()
{
    RegisterService(std::make_shared<ConsoleService>());
    RegisterService(std::make_shared<GameService>());
    RegisterService(std::make_shared<InputService>());
    RegisterService(std::make_shared<RulesService>());
    RegisterService(std::make_shared<PlayerService>());

    for (const auto& service : serviceInstances)
    {
        service->Init();
    }

    std::shared_ptr<GameService> gameService = GetService<GameService>();
    std::shared_ptr<RulesService> rulesService = GetService<RulesService>();
    std::shared_ptr<PlayerService> playerService = GetService<PlayerService>();

    gameService->SetRulesService(rulesService);
    gameService->SetPlayerServices(playerService);

    gameService->MainMenu();
    //TODO:Change this to SetDependencies?
}