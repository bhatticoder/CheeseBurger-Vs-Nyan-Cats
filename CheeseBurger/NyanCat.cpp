#include "Nyancat.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Nyancat::Nyancat(int startRow, int startCol, int speed, int level, Cheeseburger* burger)
    : GameObject(startRow, startCol, rows, cols), falling_speed(speed), level(level),
    playerLives(3), player_col(startCol), burger(burger), superNyanSpawned(false), superNyanMoved(0) {
    initializeCats();
}

void Nyancat::initializeCats() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row = -1; // Offscreen
        cats[i].col = rand() % (cols - 2) + 1; // Random column
    }
}

void Nyancat::fall() {
    // Check if score is high enough to spawn Super Nyan
    if (burger && burger->getScore() >= 50 && !superNyanSpawned) {
        // Spawn Super Nyan and make it move twice as fast
        superNyanSpawned = true;
        superNyanMoved = 0; // Reset movement count
        std::cout << "Super Nyan has spawned! You have reached Level 2!" << std::endl;
        std::cout << "The falling speed of Nyan Cats has increased!" << std::endl;
        falling_speed *= 2; // Double the falling speed after reaching level 2
        // Increase player's lives by 1 when Level 2 is reached
        playerLives++;
        std::cout << "Player lives increased to: " << playerLives << std::endl;
    }

    // Move the Nyan Cats or Super Nyan based on the condition
    for (int i = 0; i < maxCats; ++i) {
        if (superNyanSpawned && superNyanMoved < 2) {
            // Super Nyan moves twice as fast
            cats[i].row += falling_speed * 2;
            superNyanMoved++;
        }
        else {
            // Regular Nyan Cats
            cats[i].row += falling_speed;
        }

        if (cats[i].row >= rows - 1) { // Reset cat if it reaches the bottom
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;
            if (burger) {
                burger->updateScore(10);
            }
        }
    }
}
void Nyancat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
void Nyancat::collide(GameObject* collideobject) {
    for (int i = 0; i < maxCats; ++i) {
        // Check if we are dealing with Super Nyan
        bool isSuperNyan = (superNyanSpawned && cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4);
        // Check for collision with regular Nyan Cats
        bool isRegularCat = (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4);
        // Check collision with Super Nyan or Regular Nyan Cats
        if (isSuperNyan || isRegularCat) {
            // Output the collision result based on the type of Nyan
            if (isSuperNyan) {
                std::cout << "Oh no! Super Nyan collided!" << std::endl;
            }
            else {
                std::cout << "Oh no! Nyan Cat collided!" << std::endl;
            }
            playerLives--; // Decrease player lives for both types of Nyan
            if (playerLives <= 0) {
                std::cout << "Game Over! The player is out of lives!" << std::endl;
                return;
            }
        }
    }
}
void Nyancat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                std::cout << "="; // Draw player
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        if (superNyanSpawned && superNyanMoved < 2) {
                            std::cout << "S"; // Draw Super Nyan
                        }
                        else {
                            std::cout << "N"; // Draw regular Nyan Cat
                        }
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

int Nyancat::getLives() const {
    return playerLives;
}

int Nyancat::getRow() const {
    return -1;
}

int Nyancat::getPlayerCol() const {
    return player_col;
}

