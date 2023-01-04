#include "GameEngine.h"

void GameEngine::draw()
{
	m_Window.clear(sf::Color::White);

	m_Window.draw(player.getPlayerStartingPosition());
	m_Window.setView(m_MainView);
	m_Window.display();
}
