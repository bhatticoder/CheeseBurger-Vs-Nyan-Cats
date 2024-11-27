#pragma once
#include"GameObject.h"
#include <iostream>
enum powerup_type
{
	Shield,
	score_multiplier,
	speed_boost
};
class Powerup :public GameObject
{
private:
	int type;
	int duration;
	bool isactive;
public:
	Powerup(int x, int y, powerup_type type, int duration);
	void activate();
	void deactivate();
	void reset();
};