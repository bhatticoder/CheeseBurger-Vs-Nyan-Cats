#include "Cheeseburger.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
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
    printColored("=", YELLOW);
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
// Manage shield timer and state
int Cheeseburger::getTimer() {
    if (shieldActive) {
        if (shieldTimer > 0) {
            shieldTimer--; // Decrease shield time
        }
        if (shieldTimer == 0) {
            shieldActive = false; // Deactivate the shield after time runs out
            std::cout << "Shield deactivated.\n";
        }
    }
    return shieldTimer; // Return the remaining shield time
}
// Activate shield and set timer
void Cheeseburger::activateShield() {
    shieldActive = true;
    shieldTimer = 10; // Set shield duration to 10 seconds
    std::cout << "Shield activated! Lives are protected for 10 seconds.\n";
}
// Update shield status in real time
int Cheeseburger::updateShield() {
    if (shieldActive) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Wait for 1 second
        shieldTimer--;  // Decrease shield time
        if (shieldTimer <= 0) {
            shieldActive = false;  // Shield expires after time runs out
            std::cout << "Shield deactivated.\n";
        }
    }
    return 0;
}
// Check if shield is active
bool Cheeseburger::isShieldActive() const {
    return shieldActive;
}
// Increase speed (for SpeedBooster or other power-ups)
void Cheeseburger::increaseSpeed() {
    speed = 4; // Temporary speed boost
    std::cout << "Speed Boost Activated! Speed increased to 4.\n";
}
// Reset speed to default
void Cheeseburger::resetSpeed() {
    speed = defaultSpeed; // Reset speed to the normal value
    std::cout << "Speed Reset. Current speed: " << speed << std::endl;
}
// Overload output operator to display Cheeseburger state
std::ostream& operator<<(std::ostream& os, const Cheeseburger& burger) {
    os << "Cheeseburger [Lives: " << burger.lives
        << ", Score: " << burger.score
        << ", Column: " << burger.player_col
        << ", Speed: " << burger.speed << "]";
    return os;
}