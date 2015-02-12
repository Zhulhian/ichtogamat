#include "Engine.h"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

Engine::Engine()
{
}

Engine::~Engine()
{

}

bool Engine::Init()
{
	sf::Vector2i screenDimensions(800, 400);
	window = new sf::RenderWindow(sf::VideoMode(screenDimensions.x, screenDimensions.y, 32), "ICHTOGAMAT");
	window->setFramerateLimit(60);

    sf::Texture bg_texture;
    if(!bg_texture.loadFromFile("desert.png"))
	{
		return false;
	}

    sf::Sprite bg;
    bg.setTexture(bg_texture);
    bg.setPosition(sf::Vector2f(0, 0));

    sf::Clock frameClock;

	if(!window)
		return false;
	return true;
}

void Engine::RenderFrame()
{
	//window->clear(sf::Color::Blue);
	window->draw(bg);
	window->display();
}

void Engine::ProcessInput()
{
	sf::Event event;

	// Loop through all window events
	while (window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window->close();
	}
}

void Engine::Update()
{
	sf::Time frameTime;
	frameTime = frameClock.restart();
}

void Engine::MainLoop()
{
	// Loop until the window is closed
	while (window->isOpen())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Go()
{
	if(!Init())
		throw "Could not initialize Engine";

	MainLoop();
}

