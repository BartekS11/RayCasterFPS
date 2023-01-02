#include "GameEngine.h"


GameEngine::GameEngine()
{
	sf::Vector2f resolution;

	//resolution.x = sf::VideoMode::getDesktopMode().width;
	//resolution.y = sf::VideoMode::getDesktopMode().height;
	resolution.x = Constants::SCREEN_W;
	resolution.y = Constants::SCREEN_H;
	m_Window.create(sf::VideoMode(resolution.x, resolution.y), "RayCasterFPS", sf::Style::Default);

	m_MainView.setSize(resolution);

}

void GameEngine::run()
{
	sf::Clock clock;

	//Main game loop
	while (m_Window.isOpen())
	{
		sf::Time dt = clock.restart();

		float dtAsSeconds = dt.asSeconds();

		handleInput();
		update(dtAsSeconds);
		draw();
	}
}
