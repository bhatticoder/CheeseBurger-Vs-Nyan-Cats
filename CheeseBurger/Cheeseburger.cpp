#include "Cheeseburger.h"
#include "NyanCat.h"
#include <iostream>
using namespace std;
// Constructor
Cheeseburger::Cheeseburger(int x, int y, int speed, int lives, int startCol)
    : GameObject(x, y, 4, 2), score(0), lives(lives), speed(speed), player_col(startCol), shieldTimer(10) {}

std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger) {
    os << "Score: " << burger.getScore();
    return os;
}
void Cheeseburger::updateScore(int increment) {
    score += increment;
    std::cout << "Score Updated: " << score << std::endl;
}
bool Cheeseburger::collide(GameObject* collideobject) {
    if (collideobject) {
        lives -= 1;
        std::cout << "Collision detected! Lives remaining: " << lives << std::endl;
    }
    if (lives <= 0) {
        std::cout << "Game Over!" << std::endl;
        return true;
    }
    return false;
}
int Cheeseburger::getLives() const {
    return lives;
}
int Cheeseburger::getScore() const {
    return score;
}
int Cheeseburger::getSpeed()const {
    return speed;
}
void Cheeseburger::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
void Cheeseburger::draw() {
    cout << "=";
}
void Cheeseburger::activateShield(int duration) {
    shieldActive = true;
    shieldTimer = duration;  // Counted down in the game loop
}

void Cheeseburger::activateScoreMultiplier(int duration) {
    scoreMultiplier = 2;  // Double score
    scoreMultiplierTimer = duration;
}

void Cheeseburger::activateSpeedBoost(int duration) {
    speedBoostActive = true;
    speedBoostTimer = duration;
}

void Cheeseburger::updatePowerupTimers() {
    if (shieldActive && --shieldTimer <= 0) shieldActive = false;
    if (scoreMultiplier > 1 && --scoreMultiplierTimer <= 0) scoreMultiplier = 1;
    if (speedBoostActive && --speedBoostTimer <= 0) speedBoostActive = false;
}
int Cheeseburger::getShieldTime() const {
    return shieldTimer;
}
void Cheeseburger::updateShield() {
    if (shieldTimer > 0) {
        --shieldTimer;
        if (shieldTimer == 0) {
            shieldActive = false;
            std::cout << "Shield Deactivated!\n";
        }
    }
}