#pragma once
#include "SFML/Graphics.hpp"

class Player 
{
private:
	sf::Vector2f m_posPlayer;

public:
	sf::Vector2f getPlayerStartingPosition();
	Player();
};