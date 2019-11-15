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

	/*void addTile(const float x, const float y);
	void removeTile();*/
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow& window);

private:
	void initialise();

	float m_maxSize;
	Tile* m_tiles[50][50];
	
};

#endif // !TILEMAP_H
