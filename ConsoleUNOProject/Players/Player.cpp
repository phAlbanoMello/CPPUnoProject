#include "Player.h"
#include <memory>

Player::Player()
{
}

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

void Player::SetHasOneCard(bool value)
{
    hasOneCard = value;
}

bool Player::GetHasOneCard() const
{
    return hasOneCard;
}

std::shared_ptr<Deck>& Player::GetHand()
{
    return hand;
}
