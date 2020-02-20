//*new*
#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject
{
public:
	void update(float dt);
	void handleInput(float dt);
	Player(sf::RenderWindow* hwnd);

	float x, y, scale;
	bool isJumping;

	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;

	sf::RenderWindow* window;
};
