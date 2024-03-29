//
// C00204076
// Brandon Seah-Dempsey
// Started at 9:48 12 November 2019
// Finished at
// Time taken:
// Known bugs:

#include "TileMap.h"

//
TileMap::TileMap(float gridSize) :
m_maxSize(gridSize)
{
	initialise();
}

//
TileMap::~TileMap()
{
	delete this;
}

//
void TileMap::initialise()
{
	for (int i = 0; i < m_maxSize; i++)
	{
		for (int j = 0; j < m_maxSize; j++)
		{
			m_tiles[i][j] = new Tile(0, i, j);
		}
	}

	m_entity = new Entity();
}


void TileMap::update(sf::Time deltaTime, sf::RenderWindow& window)
{
	tileSetting(window);
}



//
void TileMap::tileSetting(sf::RenderWindow& window)
{
	for (int i = 0; i < m_maxSize; i++)
	{
		for (int j = 0; j < m_maxSize; j++)
		{
			//
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (m_tiles[i][j]->getRect().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					// Set Tiles to green/Start
					m_tiles[i][j]->setType(1);
					m_entity->setX(m_tiles[i][j]->getPosition().x + 14);
					m_entity->setY(m_tiles[i][j]->getPosition().y + 14);
				}

				if (m_tiles[i][j]->getType() == 1)
				{
					if (!m_tiles[i][j]->getRect().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						m_tiles[i][j]->setType(0);
					}
				}

				
			}

			//
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				if (m_tiles[i][j]->getRect().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					// Set Tiles to red/Goal
					m_tiles[i][j]->setType(2);
				}

				if (m_tiles[i][j]->getType() == 2)
				{
					if (!m_tiles[i][j]->getRect().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
					{
						m_tiles[i][j]->setType(0);
					}
				}
			}

			//
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
			{
				if (m_tiles[i][j]->getRect().getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					// Set Tiles to black/Obstacle
					m_tiles[i][j]->setType(3);
				}
			}
		}// End For Loop #2
	} // End For Loop #1
}

void TileMap::render(sf::RenderWindow& window)
{

	for (int i = 0; i < m_maxSize; i++)
	{
		for (int j = 0; j < m_maxSize; j++)
		{
			m_tiles[i][j]->render(window);
		}
	}

	m_entity->render(window);
}