//*new*
#pragma once
#include "Framework/GameObject.h"

class Player : public GameObject
{
public:
	void handleInput(float dt);
	void update(float dt);
	float x, y;
};
