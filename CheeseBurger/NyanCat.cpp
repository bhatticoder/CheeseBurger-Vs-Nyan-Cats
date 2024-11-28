#include "Nyancat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
Nyancat::Nyancat(int startRow, int startCol, int speed, int level, Cheeseburger* burger)
    : GameObject(startRow, startCol, rows, cols), falling_speed(speed), level(level),
    playerLives(3), player_col(startCol), burger(burger), superNyanSpawned(false), superNyanMoved(0) {
    initializeCats();
}
void Nyancat::initializeCats() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row = -1; // Offscreen initially
        cats[i].col = rand() % (cols - 2) + 1; // Random column, within screen bounds
    }
}
void Nyancat::fall() {
    if (burger && burger->getScore() >= 50 && !superNyanSpawned) {
        superNyanSpawned = true;  // Mark that Super Nyan is now spawned
        std::cout << "Super Nyan has spawned! You have reached Level 2!" << std::endl;
        falling_speed *= 2;  // Super Nyan falls faster
        playerLives++;  // Increase player's lives at Level 2
        std::cout << "Player lives increased to: " << playerLives << std::endl;
    }
    for (int i = 0; i < maxCats; ++i) {
        if (superNyanSpawned && cats[i].row == -1) {
            cats[i].row = 0;
            cats[i].col = rand() % (cols - 2) + 1;  
        }
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;  // Reset position for random columns
            if (burger) {
                burger->updateScore(10);  // Update score regularly for each Nyan Cat
            }
        }
        else {
            cats[i].row += falling_speed;  // Regular falling speed for both types
        }
    }
}
void Nyancat::move(char direction) {
    if (direction == 'a') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd') {
        if (player_col < cols - 4) player_col++;
    }
}
void Nyancat::collide(GameObject* collideobject) {
    for (int i = 0; i < maxCats; ++i) {
        bool isRegularCat = (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4);
        bool isSuperNyan = (superNyanSpawned && cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4);
        if (isRegularCat) {
            playerLives -= 1;
        }
        if (isSuperNyan) {
            playerLives -= 1;
        }
        if (playerLives <= 0) {
            std::cout << "Game Over!" << std::endl;
            return;
        }
    }
}
void Nyancat::draw() {
    // Draw the game area with vertical borders
    for (int i = 1; i < rows - 1; ++i) {  // Start from 1, as row 0 is the top border
        std::cout << "|";  // Left vertical border
        for (int j = 1; j < cols - 1; ++j) {  // Start from 1, as column 0 is the left border
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                // Check if we need to draw the player as (==)
                if (j == player_col) {
                    std::cout << "(";  // Left bracket
                }
                else if (j == player_col + 3) {
                    std::cout << ")";  // Right bracket
                }
                else {
                    std::cout << "=";  // The equal signs in the middle
                }
            }
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
        std::cout << "|" << std::endl;  // Right vertical border
    }
}
int Nyancat::getLives() const {
    return playerLives;
}
int Nyancat::getRow() const {
    return -1;
}
int Nyancat::getPlayerCol() const {
    return player_col;
}