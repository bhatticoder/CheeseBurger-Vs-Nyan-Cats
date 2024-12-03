#include "Nyancat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <thread>
#include <chrono>

NyanCat::NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp, ScoreMultiplier* multiplier)
    : GameObject(startRow, startCol, 25, 50), falling_speed(speed), playerLives(3), player_row(startRow), player_col(startCol),
    burger(burger), powerUp(powerUp), multiplier(multiplier) {
    initializeCats();
    powerUp->initialize();
    multiplier->initialize();
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
RegularNyanCat::RegularNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp, ScoreMultiplier* multiplier)
    : NyanCat(startRow, startCol, speed, burger, powerUp, multiplier) {}

void RegularNyanCat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;  // Reset position to the top after it falls
            cats[i].col = rand() % (cols - 2) + 1;  // Random column
            burger->updateScore(10);  // Add points for each falling NyanCat
        }
        else {
            cats[i].row++;  // Fall down
        }
    }
    powerUp->fall();  // PowerUp falls
    multiplier->fall();  // Multiplier falls
    // Handle PowerUp collision with cats
    for (int i = 0; i < maxCats; ++i) {
        if (powerUp->collidesWith(cats[i].row, cats[i].col)) {
            powerUp->initialize();  // Reset PowerUp
            break;
        }
    }
    // Check multiplier collision
    if (multiplier->collidesWith(rows - 2, player_col)) {
        multiplier->initialize();  // Reset multiplier
        burger->updateScore(100);  // Boost score
    }
}

bool RegularNyanCat::collide(GameObject* collideobject) {
    return NyanCat::collide(collideobject);
}

void RegularNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) std::cout << "=";
            else if (j == 0 || j == cols - 1) std::cout << "||";
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) burger->draw();
            else if (i == powerUp->getRow() && j == powerUp->getCol()) powerUp->draw();
            else if (i == multiplier->getRow() && j == multiplier->getCol()) multiplier->draw();
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";  // Draw Nyan Cat
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|SUper Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
SuperNyanCat::SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp, ScoreMultiplier* multiplier)
    : NyanCat(startRow, startCol, speed, burger, powerUp, multiplier) {}

void SuperNyanCat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;  // Reset position to the top after it falls
            cats[i].col = rand() % (cols - 2) + 1;  // Random column
            burger->updateScore(10);  // Add points for each falling NyanCat
        }
        else {
            cats[i].row++;  // Fall down
        }
    }
    powerUp->fall();  // PowerUp falls
    multiplier->fall();  // Multiplier falls
    // Handle PowerUp collision with cats
    for (int i = 0; i < maxCats; ++i) {
        if (powerUp->collidesWith(cats[i].row, cats[i].col)) {
            powerUp->initialize();  // Reset PowerUp
            break;
        }
    }
    // Check multiplier collision
    if (multiplier->collidesWith(rows - 2, player_col)) {
        multiplier->initialize();  // Reset multiplier
        burger->updateScore(100);  // Boost score
    }
}

bool SuperNyanCat::collide(GameObject* collideobject) {
    return NyanCat::collide(collideobject);
}

void SuperNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) std::cout << "=";
            else if (j == 0 || j == cols - 1) std::cout << "||";
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) burger->draw();
            else if (i == powerUp->getRow() && j == powerUp->getCol()) powerUp->draw();
            else if (i == multiplier->getRow() && j == multiplier->getCol()) multiplier->draw();
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";  // Draw Nyan Cat
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Mega Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
MegaNyanCat::MegaNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp, ScoreMultiplier* multiplier)
    : NyanCat(startRow, startCol, speed, burger, powerUp, multiplier) {}

void MegaNyanCat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;
            burger->updateScore(10);
        }
        else {
            cats[i].row++;
        }
    }
    powerUp->fall();
    multiplier->fall();

    // Handle PowerUp collision with cats
    for (int i = 0; i < maxCats; ++i) {
        if (powerUp->collidesWith(cats[i].row, cats[i].col)) {
            powerUp->initialize();
            break;
        }
    }
    // Check multiplier collision
    if (multiplier->collidesWith(rows - 2, player_col)) {
        multiplier->initialize();
        burger->updateScore(100);
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
    teleport();
    return false; // Default return value for no collision
}
void MegaNyanCat::teleport() {
    for (int i = 0; i < maxCats; ++i) {
        cats[i].col = rand() % (cols - 2) + 1;
        cats[i].row = rand() % 5;  // Random row, simulate teleportation
    }
}
void MegaNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) std::cout << "=";
            else if (j == 0 || j == cols - 1) std::cout << "||";
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) burger->draw();
            else if (i == powerUp->getRow() && j == powerUp->getCol()) powerUp->draw();
            else if (i == multiplier->getRow() && j == multiplier->getCol()) multiplier->draw();
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";  // Draw Mega Nyan Cat
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
}
