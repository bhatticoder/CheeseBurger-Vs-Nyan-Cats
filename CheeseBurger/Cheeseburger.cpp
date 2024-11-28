#include "Cheeseburger.h"
#include "NyanCat.h"
#include <iostream>
using namespace std;
// Constructor
Cheeseburger::Cheeseburger(int x, int y, int speed, int lives)
    : GameObject(x, y, 4, 2), score(0), lives(3), speed(speed) {
    this->x = x; // Initialize inherited member variable for x-coordinate
    this->y = y;
}
// Activate a powerup
void Cheeseburger::activate_powerup(int type) {
    switch (type) {
    case 1: // Example: Speed boost
        speed += 2;
        std::cout << "Speed Boost activated! New speed: " << speed << std::endl;
        break;
    case 2: // Example: Extra life
        lives++;
        std::cout << "Extra Life! Lives now: " << lives << std::endl;
        break;
    case 3: // Example: Score multiplier
        score += 100; // Adjust score as per logic
        std::cout << "Score Boost! Score now: " << score << std::endl;
        break;
    default:
        break;
    }
}
// Cheeseburger class's operator<< overload (if it's updating score)
std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger) {
    os << "Score: " << burger.getScore();
    return os;
}
void Cheeseburger::updateScore(int increment) {
    score += increment;
    std::cout << "Score Updated: " << score << std::endl;
}
void Cheeseburger::collide(GameObject* collideobject) {
    cout << "Colliding:";
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
    cout << "Moving Player";
}
void Cheeseburger::draw() {
    std::cout << "Drawing Cheeseburger at (" << x << ", " << y << ")" << std::endl;
}