#include "Nyancat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// NyanCat constructor
NyanCat::NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger)
    : GameObject(startRow, startCol, 20, 40), falling_speed(speed), playerLives(3),
    player_col(startCol), burger(burger) {}

int NyanCat::getLives() const {
    return playerLives;
}

int NyanCat::getRow() const {
    return -1;  // Not applicable, override in child class
}

int NyanCat::getPlayerCol() const {
    return player_col;
}
void NyanCat::initializeCats() {
   srand(static_cast<unsigned int>(time(0))); // Initialize random seed
   for (int i = 0; i < maxCats; ++i) {
       cats[i].row = -1; // Offscreen
        cats[i].col = rand() % (cols - 2) + 1; // Random column
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
// RegularNyanCat implementation
RegularNyanCat::RegularNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger)
    : NyanCat(startRow, startCol, speed, burger) {}

void RegularNyanCat::fall() {
    // Regular Nyan Cat behavior: just fall with the regular speed
    for (int i = 0; i < maxCats; ++i) {
        // Check if the cat has reached the bottom of the screen
        if (cats[i].row >= rows - 1) {
            // Reset the position of the Nyan Cat if it reaches the bottom
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;  // Random column within screen bounds
            if (burger) {
                burger->updateScore(10);  // Update the score for each Nyan Cat
            }
        }
        else {
            cats[i].row += falling_speed;  // Move the Nyan Cat down
        }
    }
}
void RegularNyanCat::move() {
    // Regular movement behavior: simple falling
    // In this case, there's no player movement, just Nyan Cat falling
}
void RegularNyanCat::collide(GameObject* collideobject) {
    // Check for collision with the player
    for (int i = 0; i < maxCats; ++i) {
        bool isRegularCat = (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4);
        if (isRegularCat) {
            playerLives -= 1;  // Decrease player lives on collision
        }
        if (playerLives <= 0) {
            std::cout << "Game Over!" << std::endl;
            return;
        }
    }
}
void RegularNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                std::cout << "="; // Draw player
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {                                          
                        std::cout << "N";
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " "; // Empty space
            }
        }
        std::cout << std::endl;
    }
}
void RegularNyanCat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Super Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
// SuperNyanCat implementation
SuperNyanCat::SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger)
    : NyanCat(startRow, startCol, speed, burger) {}
void SuperNyanCat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;  // Random column for the Super Nyan Cat
            if (burger) {
                burger->updateScore(15);  // Update score more for Super Nyan Cat (can be adjusted)
            }
        }
        else {
            cats[i].row += falling_speed * 2;  // Faster falling speed for Super Nyan Cat
        }
    }
}
void SuperNyanCat::move() {}
void SuperNyanCat::collide(GameObject* collideobject) {
    for (int i = 0; i < maxCats; ++i) {
        // Check if the Super Nyan Cat overlaps with the player (4 columns wide)
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            playerLives -= 1;
            cats[i].row = -1;  // Move offscreen to respawn
            cats[i].col = rand() % (cols - 2) + 1;
            if (playerLives <= 0) {
                std::cout << "Game Over!" << std::endl;
                return; // Exit early to avoid further processing
            }
        }
    }
}
void SuperNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                std::cout << "="; // Draw player
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " "; // Empty space
            }
        }
        std::cout << std::endl;
    }
}
void SuperNyanCat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
void SuperNyanCat::teleport() {
    // Teleport Super Nyan to a random column
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= 0) {  // Ensure Super Nyan is active (not offscreen)
            cats[i].col = rand() % (cols - 2) + 1;  // Random column within screen bounds
        }
    }
}
