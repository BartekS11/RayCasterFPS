#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "RayCasting.h"

class GameEngine
{
private:
	sf::RenderWindow m_Window;

	RayCasting m_RC;

	bool m_Playing = false;
	sf::View m_MainView;
	// Hud variable for later implementation
	sf::View m_HudView;

	void loadLevel();
	void handleInput();
	void update(float dtAsSeconds);
	void draw();

public:
	GameEngine();

	void run();
};