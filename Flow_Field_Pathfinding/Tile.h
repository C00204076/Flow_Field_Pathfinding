//
// C00204076
// Brandon Seah-Dempsey
// Started at 9:37 8 November 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

//
class Tile
{
public:
	Tile();
	Tile(int type, int gridX, int gridY);
	~Tile();

protected:
	sf::Sprite m_sprite;
	bool m_collision;
	int m_type;

private:

};

#endif // !TILE_H
