#include "InputService.h"
#include <conio.h>

void InputService::Init()
{
}

char InputService::GetPlayerInput() {
    int input = _getch();

    if (input == 13) {
        return '\n';
    }
    else {
        return static_cast<char>(input);
    }
}
