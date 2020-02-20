#include "Player.h"

Player::Player(sf::RenderWindow * hwnd)
{
	window = hwnd;

	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = false;
}

void Player::update(float dt)
{

	if (getPosition().y >= window->getSize().y - 100)
	{
		setPosition(getPosition().x, window->getSize().y - 101);
		// To make the ball bounce:
		// stepVelocity = (-stepVelocity) / 1.2f;
		stepVelocity.y = 0;
	
		isJumping = false;
	}
	else {
		sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; // ut + 1/2at^2
		stepVelocity += gravity * dt; // v = u + at
		setPosition(getPosition() + pos);
	}
	stepVelocity.x = 0;
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}
	
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		stepVelocity.x = 100;
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		stepVelocity.x = -100;
	}
}