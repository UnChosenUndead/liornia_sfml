#include "Window.hpp"

Window::Window() { Setup("Window", sf::Vector2u(640, 480)); }
Window::Window(const std::string &title, const sf::Vector2u &size) { Setup(title, size); }
Window::~Window() { Destroy(); }

void Window::Setup(const std::string title, const sf::Vector2u &size)
{
	m_windowTitle = title;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void Window::Create()
{
	auto mode = (m_isFullscreen ? sf::VideoMode::getFullscreenModes()[0]
								 : sf::VideoMode(sf::Vector2u(800,600), 32));
	// m_window.create(sf::VideoMode(sf::Vector2u(1920,1080), 32), m_windowTitle);
	m_window.create(mode, m_windowTitle);
}

void Window::Destroy()
{
	m_window.close();
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::EndDraw() { m_window.display(); }

bool Window::IsDone() { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }

sf::RenderWindow *Window::GetRenderWindow() { return &m_window; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	m_window.close();
	Create();
}

void Window::Update()
{
	while (const std::optional event = m_window.pollEvent())
	{
		if (event->is<sf::Event::Closed>()) {
			m_isDone = true;
		}
		else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				m_isDone = true;
			}
			else if(keyPressed->scancode == sf::Keyboard::Scancode::F5)
			{
				ToggleFullscreen();
			}
		}
	}
	
	// while (m_window.isOpen())
	// {
	// 	if (sf::Event::Closed)
	// 	{
	// 		m_isDone = true;
	// 	}
	// 	else if (sf::Event::KeyPressed && sf::Keyboard::Key::Escape)
	// 	{
	// 		m_isDone = true;
	// 	}
	// 	else if (sf::Event::KeyPressed && sf::Keyboard::Key::F5)
	// 	{
	// 		ToggleFullscreen();
	// 	}
	// }
}