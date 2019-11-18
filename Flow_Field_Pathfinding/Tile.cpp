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
	setColour();
	m_square.setOutlineColor(sf::Color::Black);
	m_square.setPosition(m_x * 29, m_y * 29);
}


//
void Tile::render(sf::RenderWindow& window)
{
	window.draw(m_square);
}

//
int Tile::getType()
{
	return m_type;
}

//
sf::Vector2f Tile::getPosition()
{
	return m_position;
}

//
sf::RectangleShape Tile::getRect()
{
	return m_square;
}

//
void Tile::setColour()
{
	//
	if (m_type < 0)
	{
		m_type = 0;
	}
	//
	else if (m_type > 4)
	{
		m_type = 4;
	}

	//
	if (m_type == 0)
	{
		m_square.setFillColor(sf::Color::Blue);
	}
	//
	else if (m_type == 1)
	{
		m_square.setFillColor(sf::Color::Green);
	}
	//
	else if (m_type == 2)
	{
		m_square.setFillColor(sf::Color::Red);
	}
	//
	else if (m_type == 3)
	{
		m_square.setFillColor(sf::Color::Black);
	}
	//
	else if (m_type == 4)
	{
		m_square.setFillColor(sf::Color::Yellow);
	}
}

//
void Tile::setType(int type)
{
	m_type = type;
	setColour();
}