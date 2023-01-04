#pragma once
#include "Constants.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../Levels/LevelManager.h"
#include "../Character/Player.h"

class RayCasting
{
private:
	float m_cameraX = 0.f;

	Player* player;
	// Start position
	sf::Vector2f m_pos = player->getPlayerStartingPosition();

	//Define ray x and y direction
	sf::Vector2f m_rayDir;

	// Camera plane (2d so its line)
	sf::Vector2f m_plane;

	// Current time of frame
	float m_timeCount = 0.f;

	// Which box on the map ray is in
	sf::Vector2i m_map;

	// Lenght of ray
	sf::Vector2f m_sideDist;

	// Length of distance that ray has to travel
	sf::Vector2f m_deltaDist;

	// Pointer to 2d array with level loaded
	int** m_ArrayLevel = nullptr;

	float m_prepWallDist = 0.f;

	
	// Step to the next block
	sf::Vector2i m_step;

	LevelManager m_LM;

	int m_hit = 0;
	int m_side = 0;

	void loadLevel();
public:
	RayCasting();
	void draw(sf::RenderWindow& window);
	void update(float dtAsSeconds);
};