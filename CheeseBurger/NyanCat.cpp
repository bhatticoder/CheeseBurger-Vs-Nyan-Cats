#include "NyanCat.h"
#include <cstdlib>  
#include <ctime>  
Nyancat::Nyancat(int startRow, int startCol, int speed, int level)
    : GameObject(startRow, startCol, rows, cols), playerLives(1), falling_speed(speed), player_col(startCol), isvisible(true), level(level) {
    initializeCats(); 
}
void Nyancat::initializeCats() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row = -1; 
        cats[i].col = rand() % (cols - 2) + 1; 
    }
}
void Nyancat::collide(GameObject* collideobject) {
    // Check if collideobject is a Cheeseburger (player) and check the positions
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            playerLives--;  // Decrease player's lives
            std::cout << "A Nyancat collided with the player! Lives remaining: " << playerLives << std::endl;
            if (playerLives <= 0) {
                std::cout << "Game Over! The player is out of lives!" << std::endl;
                return;
            }
        }
    }
}
void Nyancat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) {  // Ensure player does not move out of bounds
            player_col -= 1;
        }
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 2) {  // Ensure player does not move out of bounds
            player_col += 1;
        }
    }
}
// Update falling position of all Nyan Cats
void Nyancat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row += falling_speed;  // Move each cat down by its falling speed
        if (cats[i].row >= rows - 1) {  // If a cat reaches the bottom
            cats[i].row = -1;           // Reset it to start from above
            cats[i].col = rand() % (cols - 2) + 1;  // Assign a new random column
        }
    }
}
// Draw the entire grid (boundaries, player, and Nyan Cats)
void Nyancat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Draw boundaries
            if (i == 0 || i == rows - 1) {
                std::cout << "=";  // Horizontal boundary
            }
            else if (j == 0 || j == cols - 1) {
                std::cout << "||";  // Vertical boundary
            }
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) {  // Burger shape for the player
                if (j == player_col) std::cout << "(";  // Left side of the burger
                else if (j == player_col + 3) std::cout << ")";  // Right side of the burger
                else std::cout << "=";  // Middle part of the burger
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (i == cats[k].row && j == cats[k].col) {
                        std::cout << "N";  // Represent Nyan Cat as 'N'
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) {
                    std::cout << " ";  // Empty space
                }
            }
        }
        std::cout << std::endl;
    }
}
// Getter methods (optional)
int Nyancat::getRow() const {
    return -1;  // Not applicable for the entire grid
}
int Nyancat::getPlayerCol() const {
    return player_col;
}
int Nyancat::getLives() const {
    return playerLives;
}