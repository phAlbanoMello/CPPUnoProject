#include "SkipEffect.h"

void SkipEffect::ApplyEffect(GameStateService& gameState)
{
	gameState.UpdateCurrentPlayerIndex(1);
}
