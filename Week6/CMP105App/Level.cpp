#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in):
	ball(hwnd)
{
	window = hwnd;
	input = in;

	Tball.loadFromFile("gfx/Beach_Ball.png");

	ball.setInput(input);
	ball.setTexture(&Tball);
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(0, 0);
	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	// **new**
	ball.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}