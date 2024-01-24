#include "Services/ServiceLocator.h"
#include "Services/PlayerService.h"

int main()
{
    ServiceLocator::Init();

    std::shared_ptr<PlayerService> ps = ServiceLocator::GetService<PlayerService>();
    PlayerService actPs = *ps;

    actPs.Test();
}
