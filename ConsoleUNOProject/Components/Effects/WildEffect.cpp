#include "WildEffect.h"
#include "../../Services/InputService.h"
void WildEffect::ApplyEffect(GameStateService& gameState)
{
    ConsoleService::Print("Select a color rule for the next turn");
    ConsoleService::PrintDivisor();
    ConsoleService::Print("Red [R], Yellow [Y], Blue [B], Green[G]");

    char input = InputService::GetPlayerInputOfType<char>();

    switch (input)
    {
    case 'R':
        gameState.ChangeGameColor(ConsoleColor::Red);
        break;
    case 'Y':
        gameState.ChangeGameColor(ConsoleColor::Yellow);
        break;
    case 'B':
        gameState.ChangeGameColor(ConsoleColor::Blue);
        break;
    case 'G':
        gameState.ChangeGameColor(ConsoleColor::Green);
        break;
    default:
        ConsoleService::Print("Invalid input. Please select a valid color rule.");
        // Handle invalid input here
        break;
    }
}
