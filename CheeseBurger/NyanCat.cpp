#include "NyanCat.h"
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

Nyancat::Nyancat(int startRow, int startCol, int speed, int level)
    : GameObject(startRow, startCol, rows, cols), fallingspeed(speed), playerCol(startCol), isvisible(true), level(level) {
    initializeCats();  // Initialize the cats when the Nyancat object is created
}

// Initialize multiple Nyan Cats with random positions
void Nyancat::initializeCats() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row = -1;  // Start above the grid
        cats[i].col = rand() % (cols - 2) + 1;  // Random column within bounds
    }
}

// Player movement
void Nyancat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (playerCol > 1) {  // Ensure player does not move out of bounds
            playerCol -= 1;
        }
    }
    else if (direction == 'd' || direction == 'D') {
        if (playerCol < cols - 2) {  // Ensure player does not move out of bounds
            playerCol += 1;
        }
    }
}

// Update falling position of all Nyan Cats
void Nyancat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row += fallingspeed;  // Move each cat down by its falling speed
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
            else if (i == row - 6) {
                std::cout << "-";
            }
            else if (i == rows - 2 && j == playerCol) {
                std::cout << "P";  // Player character
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
    return playerCol;
}
