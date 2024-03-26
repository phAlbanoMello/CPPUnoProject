#include "ReverseEffect.h"

void ReverseEffect::ApplyEffect(GameStateService& gameState)
{
	if (gameState.GetStateData().FlowDirection == GameFlowDirection::Clockwise)
	{
		gameState.ChangeFlowDirection(GameFlowDirection::Counterclockwise);
	}
	else {
		gameState.ChangeFlowDirection(GameFlowDirection::Clockwise);
	}
}
