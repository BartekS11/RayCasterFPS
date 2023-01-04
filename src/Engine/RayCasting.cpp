#include "RayCasting.h"


RayCasting::RayCasting()
{
	m_pos.x = 22.f;
	m_pos.y = 12.f;

	m_rayDir.x = -1.f;
	m_rayDir.y = 0.f;

	m_plane.x = 0.f;
	m_plane.y = 0.66f;

	m_map.x = 0;
	m_map.y = 0;

	m_sideDist.x = 0.f;
	m_sideDist.y = 0.f;

	m_deltaDist.x = 0.f;
	m_deltaDist.y = 0.f;

	m_step.x = 0;
	m_step.y = 0;
}

void RayCasting::draw(sf::RenderWindow& window)
{
	//window.draw();
}

void RayCasting::update(float dtAsSeconds)
{
	int w = Constants::SCREEN_W;
	int h = Constants::SCREEN_H;

	for (auto x = 0; x < w; w++)
	{
		// Calculate ray directrion and position
		m_cameraX = 2 * x / static_cast<float>(w) - 1;
		m_rayDir.x = m_rayDir.x + (m_plane.x * m_cameraX);
		m_rayDir.y = m_rayDir.y + (m_plane.y * m_cameraX);

		m_map.x = static_cast<int> (m_pos.x);
		m_map.y = static_cast<int> (m_pos.y);

		// 1e30 is to avoid dividing by 0
		m_deltaDist.x = (m_rayDir.x == 0) ? 1e30f : std::abs(1 / m_rayDir.x);
		m_deltaDist.y = (m_rayDir.y == 0) ? 1e30f : std::abs(1 / m_rayDir.y);

		// Calculate X and Y ray according to ray direction
		if (m_rayDir.x < 0)
		{
			m_step.x = -1;
			m_sideDist.x = (m_pos.x - m_map.x) * m_deltaDist.x;
		}
		else
		{
			m_step.x = 1;
			m_sideDist.x = (m_pos.x + 1.f - m_map.x) * m_deltaDist.x;
		}

		if (m_rayDir.y < 0)
		{
			m_step.y = -1;
			m_sideDist.y = (m_pos.y - m_map.y) * m_deltaDist.y;
		}
		else
		{
			m_step.y = 1;
			m_sideDist.y = (m_pos.y + 1.f - m_map.y) * m_deltaDist.y;
		}

		//Start algoithm which stop when ray hit the wall
		while (m_hit == 0)
		{
			if (m_sideDist.x < m_sideDist.y)
			{
				m_sideDist.x += m_deltaDist.x;
				m_map.x += m_step.x;
				m_side = 0;
			}
			else
			{
				m_sideDist.y += m_deltaDist.y;
				m_map.y += m_step.y;
				m_side = 1;
			}
			if (m_ArrayLevel[m_map.x][m_map.y] > 0)
			{
				m_hit = 1;
			}
		}
		if (m_side == 0) m_prepWallDist = (m_sideDist.x - m_deltaDist.x);
		else          m_prepWallDist = (m_sideDist.y - m_deltaDist.y);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / m_prepWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)drawEnd = h - 1;

		// Set color of walls
		sf::Color color;
		switch (m_ArrayLevel[m_map.x][m_map.y])
		{
		case 1: color = sf::Color::Red; break;
		case 2: color = sf::Color::Green; break;
		case 3: color = sf::Color::Blue; break;
		case 4: color = sf::Color::White; break;
		default: color = sf::Color::Yellow; break;
		}

		// Create vertical line
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(x, drawStart), color),
			sf::Vertex(sf::Vector2f(x, drawEnd), color)
		};

		//m_window.draw(line, 2, sf::Lines);

	}
}
