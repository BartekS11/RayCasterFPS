#include "LevelManager.h"
#include <fstream>
#include <sstream>

int** LevelManager::nextLevel(std::string levelToLoad)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	std::ifstream inputFile(levelToLoad);
	std::string s;

	while (std::getline(inputFile, s))
	{
		++m_LevelSize.y;
	}
	m_LevelSize.x = s.length();
	inputFile.clear();
	inputFile.seekg(0, std::ios::beg);

	int** arrayLevel = new int* [m_LevelSize.y];
	for (auto i = 0; i < m_LevelSize.y; ++i)
	{
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	std::string row;
	int row_count = 0;

	while (inputFile >> row)
	{
		for (auto i = 0; i < row.length(); i++)
		{
			const char val = row[i];
			arrayLevel[row_count][i] = atoi(&val);
		}
		row_count++;
	}
	inputFile.close();

	return arrayLevel;
}

sf::Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}
