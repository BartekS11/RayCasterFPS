#include "RayCasting.h"

void RayCasting::update(float dtAsSeconds)
{
	int w = Constants::SCREEN_W;

	// Calculate ray directrion and position
	for (auto x = 0; x < w; w++)
	{
		m_cameraX = 2 * x / static_cast<float>(w) - 1;
		m_rayDirX = m_rayDirX + (m_planeX * m_cameraX);
		m_rayDirY = m_rayDirY + (m_planeY * m_cameraX);
	}
}
