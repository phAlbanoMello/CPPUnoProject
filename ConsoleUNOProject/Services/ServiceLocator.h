#pragma once
#include <memory>
#include <vector>
#include "Service.h"

static class ServiceLocator
{
private:
	static std::vector<std::shared_ptr<Service>> serviceInstances;

public :
	static void RegisterService(std::shared_ptr<Service> service);

	static void Init();

	template <typename T>
	static std::shared_ptr<T> GetService();
};

template <typename T>
std::shared_ptr<T> ServiceLocator::GetService()
{
    auto service = std::find_if(serviceInstances.begin(), serviceInstances.end(),
        [](const auto& service) { return std::dynamic_pointer_cast<T>(service) != nullptr; });

    if (service != serviceInstances.end())
    {
        return std::dynamic_pointer_cast<T>(*service);
    }

    std::cout << "Trying to get a service that was not initialized" << std::endl;
    return nullptr;
}

