#pragma once
#include "Constants.h"

class RayCasting
{
private:

	//
	float m_cameraX = 0.f;

	// Start position
	float posX = 22.f, posY = 12.f;

	float m_rayDirX = -1.f;
	float m_rayDirY = 0.f;

	// Camera plane (2d so its line)
	float m_planeX = 0.f;
	float m_planeY = 0.66f;

	// Current time of frame
	float timeCount = 0.f;

	// Which box on the map ray is in
	int m_mapX = 0;
	int m_mapY = 0;

	// Lenght of ray
	float m_sideDistX = 0.f;
	float m_sideDistY = 0.f;

	// 
	float m_deltaDistX = 0.f;
	float m_deltaDistY = 0.f;

	float m_prepWallDist = 0.f;

	int stepX = 0;
	int stepY = 0;

	int hit = 0;
	int side = 0;

public:
	RayCasting();
	void update(float dtAsSeconds);
};