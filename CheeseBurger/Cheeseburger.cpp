#include "Cheeseburger.h"
#include "NyanCat.h"
#include <iostream>
using namespace std;
// Constructor
Cheeseburger::Cheeseburger(int x, int y, int speed, int lives, int startCol)
    : GameObject(x, y, 4, 2),  // Initializes GameObject's position and dimensions
    score(0),                // Initializes score to 0
    lives(lives),            // Sets lives to the passed parameter
    speed(speed),            // Sets speed to the passed parameter
    player_col(startCol)     // Initializes player column to startCol
{}
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
        if (player_col > 0) {
            player_col--;  // Move left
        }
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) {
            player_col++;  // Move right
        }
    }
}
void Cheeseburger::draw() {
    cout << "=";
}