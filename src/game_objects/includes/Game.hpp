#pragma once
#include "Window.hpp"
#include "World.hpp"
#include "Snake.hpp"
#include "MyTextbox.hpp"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();

	sf::Time GetElapsed();
	void RestartClock();

	Window *GetWindow();

private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;

	World m_world;
	Snake m_snake;
	MyTextbox m_MyTextbox;
};