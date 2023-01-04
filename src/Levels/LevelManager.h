#pragma once

#include <SFML/Graphics.hpp>
#include "../Engine/Constants.h"


class LevelManager
{
private:
	sf::Vector2f m_StartPosition;
	sf::Vector2i m_LevelSize;

public:
	int** nextLevel(std::string levelToLoad);
	sf::Vector2i getLevelSize();

};