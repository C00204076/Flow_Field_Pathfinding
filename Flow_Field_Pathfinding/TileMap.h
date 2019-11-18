//
// C00204076
// Brandon Seah-Dempsey
// Started at 9:36 8 November 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

//
class TileMap
{
public:
	TileMap(float gridSize);
	~TileMap();

	void update(sf::Time deltaTime, sf::RenderWindow& window);
	void render(sf::RenderWindow& window);

	void tileSetting(sf::RenderWindow& window);

private:
	void initialise();

	float m_maxSize;
	Tile* m_tiles[50][50];

	int m_startTile, m_goalTile;
	
};

#endif // !TILEMAP_H
