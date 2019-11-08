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
	TileMap(float  gridSize, unsigned width, unsigned height);
	~TileMap();

	void addTile(const float x, const float y);
	void removeTile();
	void update();
	void render(sf::RenderTarget& target);

private:
	float m_gridSizeF;
	unsigned m_gridSizeU;
	unsigned m_layers;

	sf::Vector2u m_maxSize;

	std::vector< std::vector< std::vector<Tile*> > > m_map;
};

#endif // !TILEMAP_H
