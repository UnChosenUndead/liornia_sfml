#include "Game.hpp"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
			   m_snake(m_world.GetBlockSize(), &m_MyTextbox),
			   m_world(sf::Vector2u(800, 600))
{
	m_clock.restart();
	srand(time(nullptr));

	m_MyTextbox.Setup(5, 14, 350, sf::Vector2f(225, 0));
	m_elapsed = 0.0f;

	m_MyTextbox.Add("Seeded random number generator with: " + std::to_string(time(nullptr)));
}

Game::~Game() {}

sf::Time Game::GetElapsed() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_elapsed += m_clock.restart().asSeconds(); }
Window *Game::GetWindow() { return &m_window; }

void Game::HandleInput()
{
	// Input handling.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_snake.GetPhysicalDirection() != Direction::Down)
	{
		m_snake.SetDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && m_snake.GetPhysicalDirection() != Direction::Up)
	{
		m_snake.SetDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && m_snake.GetPhysicalDirection() != Direction::Right)
	{
		m_snake.SetDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && m_snake.GetPhysicalDirection() != Direction::Left)
	{
		m_snake.SetDirection(Direction::Right);
	}
}

void Game::Update()
{
	m_window.Update();
	float timestep = 1.0f / m_snake.GetSpeed();
	if (m_elapsed >= timestep)
	{
		m_snake.Tick();
		m_world.Update(m_snake);
		m_elapsed -= timestep;
		if (m_snake.HasLost())
		{
			m_MyTextbox.Add("GAME OVER! Score: " + std::to_string((long long)m_snake.GetScore()));
			m_snake.Reset();
		}
	}
}

void Game::Render()
{
	m_window.BeginDraw();
	// Render here.
	m_world.Render(*m_window.GetRenderWindow());
	m_snake.Render(*m_window.GetRenderWindow());
	m_MyTextbox.Render(*m_window.GetRenderWindow());

	m_window.EndDraw();
}