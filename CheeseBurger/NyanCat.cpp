#include "Nyancat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <thread>
#include <chrono>
NyanCat::NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, shield* powerUp, ScoreMultiplier* multiplier, SpeedBooster* booster)
    : GameObject(startRow, startCol, 25, 50), falling_speed(speed), playerLives(3), player_row(startRow), player_col(startCol),
    burger(burger), powerUp(powerUp), multiplier(multiplier), booster(booster) {
    initializeCats();
    powerUp->initialize();
    multiplier->initialize();
    booster->initialize();
}
int NyanCat::getLives() const {
    return playerLives;
}
int NyanCat::getRow() const {
    return player_row;
}
int NyanCat::getPlayerCol() const {
    return player_col;
}
void NyanCat::initializeCats() {
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row = -1;  // Start at the top of the screen
        cats[i].col = rand() % (cols - 2) + 1;  // Random column for each falling cat
    }
}
void NyanCat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
void NyanCat::displayStatus() {
    std::cout << "Score: " << burger->getScore()
        << " | Lives: " << burger->getLives()
        << "\n";
}
bool NyanCat::collide(GameObject* collideobject) {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            Cheeseburger* burger = dynamic_cast<Cheeseburger*>(collideobject);
            if (burger) {
                burger->collide(this);
            }
            cats[i].row = -1;  // Reset falling cat
            return true; // Collision occurred
        }
    }
    return false; // No collision
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Regular Nyan Cat Implementation|////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
RegularNyanCat::RegularNyanCat(int param1, int param2, int param3, Cheeseburger* burger, shield* shld, ScoreMultiplier* multiplier, SpeedBooster* booster)
    : NyanCat(param1, param2, param3, burger, shld, multiplier, booster) {
    // Initialization logic here
}
void RegularNyanCat::fall() {
    // Update cats falling
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1; // Reset position to the top after it falls
            cats[i].col = rand() % (cols - 2) + 1;  // Random column
            burger->updateScore(10);  // Add points for each falling NyanCat
        }
        else {
            cats[i].row++;  // Move down one row
        }
    }
    // Power-ups, multipliers, and speed booster should fall as well
    powerUp->fall();
    multiplier->fall();
    booster->fall();
    if (powerUp->collidesWith(rows - 2, player_col)) {
        powerUp->initialize();  // Reset shield position
        powerUp->activateShield(burger);  // Activate shield on collision
        std::cout << "Shield picked up! Burger is now protected for 10 seconds.\n";
    }
    // Check multiplier collision
    if (multiplier->collidesWith(rows - 2, player_col)) {
        multiplier->initialize();  // Reset multiplier
        burger->updateScore(100);  // Boost score
    }
    // Check SpeedBooster collision with the Cheeseburger
    if (booster->collidesWith(rows - 2, player_col)) {
        booster->initialize();  // Reset booster position
        booster->activateSpeedBoost(burger);  // Activate speed boost on collision
    }
}
bool RegularNyanCat::collide(GameObject* collideobject) {
    return NyanCat::collide(collideobject);
}
void RegularNyanCat::draw() {
    // Draw the game objects (cats, power-ups, cheeseburger, speed booster)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) printColored("=", BLUE);  // Top and bottom border
            else if (j == 0 || j == cols - 1) printColored("||", BLUE);  // Side border
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) burger->draw();  // Draw cheeseburger at player's position
            else if (i == powerUp->getRow() && j == powerUp->getCol()) powerUp->draw();  // Draw power-up
            else if (i == multiplier->getRow() && j == multiplier->getCol()) multiplier->draw();  // Draw multiplier
            else if (i == booster->getRow() && j == booster->getCol()) booster->draw();  // Draw SpeedBooster
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        printColored("N", MAGENTA);  // Draw Nyan Cat
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " ";  // Empty space if no object
            }
        }
        std::cout << std::endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|SUper Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
SuperNyanCat::SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, shield* powerUp, ScoreMultiplier* multiplier, SpeedBooster* booster)
    : NyanCat(startRow, startCol, speed, burger, powerUp, multiplier, booster) {
    // Implementation here
}
void SuperNyanCat::fall() {
    // Update cats falling
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1; // Reset position to the top after it falls
            cats[i].col = rand() % (cols - 2) + 1;  // Random column
            burger->updateScore(15);  // Add points for each falling NyanCat
        }
        else {
            cats[i].row++;  // Move down one row
        }
    }

    // Power-ups, multipliers, and speed booster should fall as well
    powerUp->fall();
    multiplier->fall();
    booster->fall();

    if (powerUp->collidesWith(rows - 2, player_col)) {
        powerUp->initialize();  // Reset shield position
        powerUp->activateShield(burger);  // Activate shield on collision
        std::cout << "Shield picked up! Burger is now protected for 10 seconds.\n";
    }
    // Check multiplier collision
    if (multiplier->collidesWith(rows - 2, player_col)) {
        multiplier->initialize();  // Reset multiplier
        burger->updateScore(100);  // Boost score
    }

    // Check SpeedBooster collision with the Cheeseburger
    if (booster->collidesWith(rows - 2, player_col)) {
        booster->initialize();  // Reset booster position
        booster->activateSpeedBoost(burger);  // Activate speed boost on collision
    }
}

bool SuperNyanCat::collide(GameObject* collideobject) {
    return NyanCat::collide(collideobject);
}

void SuperNyanCat::draw() {
    // Draw the game objects (cats, power-ups, cheeseburger, speed booster)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) printColored("=", BLUE);  // Top and bottom border
            else if (j == 0 || j == cols - 1) printColored("||", BLUE);  // Side border
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) burger->draw();  // Draw cheeseburger at player's position
            else if (i == powerUp->getRow() && j == powerUp->getCol()) powerUp->draw();  // Draw power-up
            else if (i == multiplier->getRow() && j == multiplier->getCol()) multiplier->draw();  // Draw multiplier
            else if (i == booster->getRow() && j == booster->getCol()) booster->draw();  // Draw SpeedBooster
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        printColored("N", MAGENTA);  // Draw Nyan Cat
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " ";  // Empty space if no object
            }
        }
        std::cout << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Mega Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
MegaNyanCat::MegaNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, shield* powerUp, ScoreMultiplier* multiplier, SpeedBooster* booster)
    : NyanCat(startRow, startCol, speed, burger, powerUp, multiplier, booster) {
}

void MegaNyanCat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 2) {  // Check if the cat reaches the bottom
            cats[i].row = -1;  // Reset position to the top after it falls
            cats[i].col = rand() % (cols - 2) + 1;  // Random column
            burger->updateScore(10);  // Add points for each falling NyanCat
        }
        else {
            cats[i].row++;  // Move down one row
        }

        // Add individual teleportation while falling
        if (rand() % 10 == 0) { // 1 in 10 chance
            cats[i].col = rand() % (cols - 2) + 1; // Random column
            cats[i].row = rand() % 5;              // Random row (near the top)
        }
    }

    // Group teleportation


    // Power-ups, multipliers, and speed booster should fall as well
    powerUp->fall();
    multiplier->fall();
    booster->fall();

    if (powerUp->collidesWith(rows - 2, player_col)) {
        powerUp->initialize();  // Reset shield position
        powerUp->activateShield(burger);  // Activate shield on collision
        std::cout << "Shield picked up! Burger is now protected for 10 seconds.\n";
    }
    // Check multiplier collision
    if (multiplier->collidesWith(rows - 2, player_col)) {
        multiplier->initialize();  // Reset multiplier
        burger->updateScore(100);  // Boost score
    }

    // Check SpeedBooster collision with the Cheeseburger
    if (booster->collidesWith(rows - 2, player_col)) {
        booster->initialize();  // Reset booster position
        booster->activateSpeedBoost(burger);  // Activate speed boost on collision
    }
}

bool MegaNyanCat::collide(GameObject* collideobject) {
    // Check for collision with the Cheeseburger (player)
    for (int i = 0; i < maxCats; ++i) {
        // Check if the cat's position overlaps with the player's position
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            if (collideobject) {
                Cheeseburger* burger = dynamic_cast<Cheeseburger*>(collideobject);
                if (burger) {
                    burger->collide(this); // Trigger cheeseburger's collision logic
                }
            }
            // Reset the cat to the top after collision
            cats[i].row = -1; // Start falling again from the top
            cats[i].col = rand() % (cols - 2) + 1;
        }
    }
    return false; // Default return value for no collision
}
void MegaNyanCat::teleport() {
    for (int i = 0; i < maxCats; ++i) {
        // Each cat has a 20% chance to teleport randomly during its fall
        if (rand() % 5 == 0) { // 1 in 5 chance
            cats[i].col = rand() % (rows - 2) + 1; // Random column
            cats[i].row = rand() % 5;              // Random row (near the top)
        }
    }
    // Group teleportation: Occasionally teleport all cats together
    if (rand() % 10 == 0) { // 1 in 10 chance
        for (int i = 0; i < maxCats; ++i) {
            cats[i].col = rand() % (rows - 2) + 1; // Random column
            cats[i].row = rand() % 5;              // Random row (near the top)
        }
    }
}

void MegaNyanCat::draw() {
    // Draw the game objects (cats, power-ups, cheeseburger, speed booster)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) printColored("=", BLUE);  // Top and bottom border
            else if (j == 0 || j == cols - 1) printColored("||", BLUE);  // Side border
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) burger->draw();  // Draw cheeseburger at player's position
            else if (i == powerUp->getRow() && j == powerUp->getCol()) powerUp->draw();  // Draw power-up
            else if (i == multiplier->getRow() && j == multiplier->getCol()) multiplier->draw();  // Draw multiplier
            else if (i == booster->getRow() && j == booster->getCol()) booster->draw();  // Draw SpeedBooster
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        printColored("N", MAGENTA);  // Draw Nyan Cat
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " ";  // Empty space if no object
            }
        }
        std::cout << std::endl;
    }
}