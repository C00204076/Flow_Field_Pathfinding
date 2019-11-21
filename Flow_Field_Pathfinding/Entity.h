//
// C00204076
// Brandon Seah-Dempsey
// Started at 16:20 21 November 2019
// Finished at
// Time taken:
// Known bugs:

#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics.hpp"

class Entity
{
public:
	Entity();
	~Entity();

	void render(sf::RenderWindow& window);

	sf::Vector2f getPosition();
	sf::RectangleShape getRect();

	void setX(int x);
	void setY(int y);

private:
	void initialise();
	sf::RectangleShape m_square;
	sf::Vector2f m_position;
	int m_x, m_y;
};
#endif // !ENTITY_H

