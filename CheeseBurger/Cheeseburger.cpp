#include "Cheeseburger.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
Cheeseburger::Cheeseburger(int x, int y, int speed, int lives, int startCol)
    : GameObject(x, y, 4, 2), score(0), lives(lives), speed(speed), player_col(startCol),
    shieldActive(false), shieldTimer(0) {}

// Update score
void Cheeseburger::updateScore(int points) {
    score += points;
    std::cout << "Score updated! Current score: " << score << "\n";
}

// Handle collisions
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
// Get lives
int Cheeseburger::getLives() const {
    return lives;
}

// Get score
int Cheeseburger::getScore() const {
    return score;
}

// Get speed
int Cheeseburger::getSpeed() const {
    return speed;
}

// Draw cheeseburger
void Cheeseburger::draw() {
    cout << "=";
}

// Move cheeseburger based on input direction
void Cheeseburger::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        player_col = std::max(0, player_col - speed);  // Move left
    }
    else if (direction == 'd' || direction == 'D') {
        player_col = std::min(cols - 1, player_col + speed);  // Move right
    }
    std::cout << "Cheeseburger moved to column: " << player_col << "\n";
}

// Activate shield
void Cheeseburger::activateShield() {
    shieldActive = true;
    shieldTimer = 10;  // Set shield duration to 10 seconds
    std::cout << "Shield activated! You are invincible for 10 seconds.\n";
}

// Update shield timer
void Cheeseburger::updateShield() {
    if (shieldActive) {
        if (shieldTimer > 0) {
            shieldTimer--;
            std::cout << "Shield time remaining: " << shieldTimer << " seconds.\n";
        }
        else {
            shieldActive = false;
            std::cout << "Shield deactivated!\n";
        }
    }
}

// Check if shield is active
bool Cheeseburger::isShieldActive() const {
    return shieldActive;
}

// Overload output operator
std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger) {
    os << "Cheeseburger [Lives: " << burger.lives
        << ", Score: " << burger.score
        << ", Column: " << burger.player_col << "]";
    return os;
}
