//
// C00204076
// Brandon Seah-Dempsey
// Started at 10:08 8 November 2019
// Finished at
// Time taken:
// Known bugs:

#include "Game.h"

/// <summary>
/// 
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1450, 1450, 32}, "Flow Field" },
	is_running{ true }
{
	initialise();
}

/// <summary>
/// 
/// </summary>
Game::~Game()
{
	//delete this;
}

/// <summary>
/// 
/// </summary>
void Game::initialise()
{
	m_tileMap = new TileMap((float)50.0f);
}

/// <summary>
/// 
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			processEvents();
			update(timeSinceLastUpdate);
			timeSinceLastUpdate -= timePerFrame;
			//timeSinceLastUpdate = sf::Time::Zero;
		}

		render();
	}
}

/// <summary>
/// 
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				is_running = false;
			}
		}

		if (sf::Event::KeyPressed == event.type) //user pressed a key
		{
			
		}
		if (sf::Event::MouseButtonPressed == event.type || sf::Event::MouseButtonReleased == event.type) //user pressed a key
		{
			
		}

		processGameEvents(event);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="event"></param>
void Game::processGameEvents(sf::Event& event)
{
	//Check if the event is a mouse release event

	switch (event.type)
	{
	case sf::Event::KeyPressed:
		//m_keyhandler.updateKey(event.key.code, true);
		break;
	case sf::Event::KeyReleased:
		//m_keyhandler.updateKey(event.key.code, false);
		break;
	default:
		break;
	}
}

/// <summary>
/// 
/// </summary>
void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}

	}
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void Game::update(sf::Time deltaTime)
{
	if (!is_running)
	{
		m_window.close();
	}

	m_tileMap->update(deltaTime, m_window);
}

/// <summary>
/// 
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black); //Set background to black

	m_tileMap->render(m_window);

	m_window.display();
}