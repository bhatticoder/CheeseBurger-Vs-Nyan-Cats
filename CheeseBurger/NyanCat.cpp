#include "NyanCat.h"
#include <iostream>
using namespace std;

Nyancat::Nyancat(int startRow, int startCol, int speed, int level)
    : GameObject(startRow, startCol, 40, 60), fallingspeed(speed), isvisible(true), level(level) {
    row = -1; // Start above the grid
    col = startCol; // Start at the given column
    playerCol = startCol / 2;  // Initial player position, separate from Nyan Cat
}

// Move the player left or right based on user input
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

// Nyan Cat falling logic (Nyan Cat moves down automatically)
void Nyancat::fall() {
    if (isvisible) {
        row += fallingspeed; // Move down by falling speed
        if (row >= rows - 1) {
            row = -1;  // Reset Nyan Cat to start from above
            col = cols / 2;  // Start at the middle of the grid
            isvisible = true;
        }
    }
}

// Draw the game grid and objects (player and Nyan Cat)
void Nyancat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Draw boundaries
            if (i == 0 || i == rows - 1) {  // Top and bottom borders
                cout << "=";  // Horizontal boundary
            }
            else if (j == 0 || j == cols - 1) {  // Left and right borders
                cout << "||";  // Vertical boundary
            }
            else if (i == rows - 2 && j == playerCol) {  // Player at the bottom center
                cout << "P";  // Player character
            }
            else if (i == row && j == col) {  // Draw Nyan Cat
                cout << "N";  // Represent Nyan Cat as 'N'
            }
            else {
                cout << " "; // Empty space
            }
        }
        cout << endl;
    }
}
