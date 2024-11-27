#pragma once
#include"GameObject.h"
class Cheeseburger :public GameObject
{
	int score;
	int lives;
	int speed;
public:
	Cheeseburger(int x, int y, int speed, int lives);
	virtual void collide(GameObject* collideobject) = 0;
	void activate_powerup(int type);
};