#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML/Graphics.hpp>

class Engine
{
private:
	// SFML RenderWindow thingy
	sf::RenderWindow* window;

	// Initialize the engine
	bool Init();

	// Main Game Loop
	void MainLoop();

	// Renders one frame of game (no rhyme intended)
	void RenderFrame();

	// Processes user input and stuff (events)
	void ProcessInput();

	// Updates all Engine internals
	void Update();

public:
	Engine();
	~Engine();

	// Starts the engine
	void Go();
};

#endif // _ENGINE_H
