#include "Player.h"
#include <memory>

Player::Player(std::string name) : name(name)
{
}

std::string& Player::GetName()
{
    return name;
}

Card Player::PlayCard(std::string id)
{
    return Card();
}

bool Player::GetHasShoutedUNO() const
{
    return hasShoutedUNO;
}

void Player::SetShout(bool value) {
    hasShoutedUNO = value;
}

std::shared_ptr<Hand>& Player::GetHand()
{
    return hand;
}
