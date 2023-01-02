#include "GameEngine.h"

void GameEngine::handleInput()
{
	sf::Event event;

	// Handling inputs for game start
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				m_Playing = true;
			}
		}
	}
}
