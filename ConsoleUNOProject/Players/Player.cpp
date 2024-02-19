#include "Player.h"
#include <memory>

Player::Player()
{
}

Player::Player(std::string name, std::string standDescription) : _name(name), _standDescription(standDescription)
{
}

std::string& Player::GetName()
{
    return _name;
}

bool Player::GetHasShoutedUNO() const
{
    return _hasShoutedUNO;
}

void Player::SetShout(bool value) {
    _hasShoutedUNO = value;
}

void Player::SetHasOneCard(bool value)
{
    _hasOneCard = value;
}

void Player::SelectAsPlayerCharacter()
{
    _isPlayerCharacter = true;
}

bool Player::GetHasOneCard() const
{
    return _hasOneCard;
}

bool Player::GetIsPlayerCharacter()
{
    return _isPlayerCharacter;
}

std::shared_ptr<Deck>& Player::GetHand()
{
    return _hand;
}

std::string Player::GetStandDescription() {
    return _standDescription;
}
