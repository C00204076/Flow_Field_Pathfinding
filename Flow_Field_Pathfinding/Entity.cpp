//
// C00204076
// Brandon Seah-Dempsey
// Started at 16:45 21 November 2019
// Finished at
// Time taken:
// Known bugs:

#include "Entity.h"

//
Entity::Entity()
{
	initialise();
}

//
Entity::~Entity()
{
	delete this;
}

//
void Entity::initialise()
{
	m_position = sf::Vector2f(0, 0);
	m_x = 0;
	m_y = 0;

	m_square.setSize(sf::Vector2f(8, 8));
	m_square.setFillColor(sf::Color::White);
	m_square.setOutlineColor(sf::Color::White);
	m_square.setPosition(m_position);
}

//
void Entity::render(sf::RenderWindow& window)
{
	window.draw(m_square);
}

//
sf::Vector2f Entity::getPosition()
{
	return m_position;
}

//
sf::RectangleShape Entity::getRect()
{
	return m_square;
}

//
void Entity::setX(int x) 
{
	m_x = x;
	m_position = sf::Vector2f(m_x, m_position.y);
	m_square.setPosition(m_position);
}
//
void Entity::setY(int y)
{
	m_y = y;
	m_position = sf::Vector2f(m_position.x, m_y);
	m_square.setPosition(m_position);
}