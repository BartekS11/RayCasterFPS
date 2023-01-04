#include "Player.h"

sf::Vector2f Player::getPlayerStartingPosition()
{
	return m_posPlayer;
}

Player::Player()
{
	m_posPlayer.x = 22.f;
	m_posPlayer.y = 12.f;

	sf::RectangleShape player(m_posPlayer);
}
