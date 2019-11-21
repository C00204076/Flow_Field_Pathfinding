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

	void render(sf::RenderWindow& window);

	int getType();
	sf::Vector2f getPosition();
	sf::RectangleShape getRect();

	void setColour();
	void setType(int type);

private:
	void initialise();
	sf::RectangleShape m_square;
	sf::Vector2f m_position;
	int m_type, m_x, m_y;
	int m_value;
};

#endif // !TILE_H
