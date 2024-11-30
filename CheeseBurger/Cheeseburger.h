#pragma once
#include "GameObject.h"
class Cheeseburger :public GameObject
{
	int score;
	int lives;
	int speed;
	int player_col;
	bool shieldActive = false;
	int shieldTimer;
	int scoreMultiplier = 1; // Default is 1 (no multiplier)
	int scoreMultiplierTimer = 0;
	bool speedBoostActive = false;
	int speedBoostTimer = 0;
	int row, col, gridCols, gridRows, someValue;
public:
	Cheeseburger(int x, int y, int speed, int lives, int startCol);
	bool collide(GameObject* collideobject)override;
	//void activate_powerup(int type);
	void updateScore(int points);
	void draw()override;
	void move(char direction)override;
	// Getters
	int getLives() const;
	int getScore() const;
	int getSpeed()const;
	// Declare the << operator here
	void activateShield(int duration);
	void activateScoreMultiplier(int duration);
	void activateSpeedBoost(int duration);
	void updatePowerupTimers();
	void updateShield();
	int getShieldTime() const;
	friend std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger);
};