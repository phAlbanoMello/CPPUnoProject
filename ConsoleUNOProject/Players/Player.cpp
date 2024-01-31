#include "Player.h"
#include <memory>

Player::Player(std::string name) : name(name)
{
}

std::string& Player::GetName()
{
    return name;
}

bool Player::GetHasShoutedUNO() const
{
    return hasShoutedUNO;
}

void Player::SetShout(bool value) {
    hasShoutedUNO = value;
}

std::shared_ptr<Deck>& Player::GetHand()
{
    return hand;
}
