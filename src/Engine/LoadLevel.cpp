#include "GameEngine.h"
#include "../Levels/LevelManager.h"

void RayCasting::loadLevel()
{
	//TODO implement load level from text file

	for (auto i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	m_ArrayLevel = m_LM.nextLevel("Level1.txt");
}