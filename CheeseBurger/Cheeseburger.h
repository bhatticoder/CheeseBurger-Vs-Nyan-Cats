#pragma once
#include "GameObject.h"
class Cheeseburger :public GameObject
{
	int score;
	int lives;
	int speed;
public:
	Cheeseburger(int x, int y, int speed, int lives);
	void collide(GameObject* collideobject)override;
	void activate_powerup(int type);
	void updateScore(int points);
	void draw()override;
	void move(char direction)override;
	// Getters
	int getLives() const;
	int getScore() const;
	int getSpeed()const;
	// Declare the << operator here
	friend std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger);
};