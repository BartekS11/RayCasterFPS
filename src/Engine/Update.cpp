#include "GameEngine.h"

void GameEngine::update(float dtAsSeconds)
{
	if (m_Playing)
	{
		m_RC.update(dtAsSeconds);
	}
}
