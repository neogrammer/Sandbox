#include "GameState.h"

bool GameState::isClosing()
{
    return closing;
}

void GameState::resetPending()
{
    mPendingType = GStateType::None;
}
