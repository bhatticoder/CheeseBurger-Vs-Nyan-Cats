#include "Cheeseburger.h"
#include "NyanCat.h"
#include <iostream>
using namespace std;
// Constructor
Cheeseburger::Cheeseburger(int x, int y, int speed, int lives)
    : GameObject(x, y, 4, 2), score(0), lives(lives), speed(speed) {}
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
        std::cout << "Unknown powerup type!" << std::endl;
    }
}