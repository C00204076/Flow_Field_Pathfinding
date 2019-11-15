//
// C00204076
// Brandon Seah-Dempsey
// Started at 10:27 8 November 2019
// Finished at
// Time taken:
// Known bugs:

#include "Tile.h"

//
Tile::Tile()
{
	//initialise();
}

//
Tile::Tile(int type, int gridX, int gridY) :
	m_type(type),
	m_x(gridX),
	m_y(gridY)
{
	initialise();
}

//
Tile::~Tile()
{
	delete this;
}

//
void Tile::initialise()
{
	m_square.setSize(sf::Vector2f(28, 28));
	m_square.setFillColor(sf::Color::Blue);
	m_square.setOutlineColor(sf::Color::Black);
	m_square.setPosition(m_x * 29, m_y * 29);
}

//
void Tile::render(sf::RenderWindow& window)
{
	window.draw(m_square);
}

//
sf::Vector2f Tile::getPosition()
{
	return m_position;
}