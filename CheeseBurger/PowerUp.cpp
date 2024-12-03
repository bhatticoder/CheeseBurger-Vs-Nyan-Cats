#include "PowerUp.h"
PowerUp::PowerUp(int totalRows, int totalCols)
    : GameObject(-1, 0, totalRows, totalCols), // Pass initial positions and dimensions to GameObject
    rows(totalRows), cols(totalCols), row(-1), col(0) {}
void PowerUp::initialize() {
    row = -1;                        // Start above the screen
    col = rand() % (cols - 2) + 1;   // Randomize the column
}
void PowerUp::fall() {
    if (row >= rows - 1) {
        row = -1;  // Reset to the top once it reaches the bottom
        col = rand() % (cols - 2) + 1;  // Random horizontal position
    }
    else {
        row++;  // Move down by one row
    }
}


int PowerUp::getRow() const {
    return row;
}
int PowerUp::getCol() const {
    return col;
}
bool PowerUp::collidesWith(int row, int col) {
    return this->row == row && this->col == col; // Simple collision check
}
void PowerUp::activateShield() {
    if (!shieldActive) {
        shieldActive = true;
        std::cout << "Shield Activated!\n";
        // Start the shield timer (set duration for the shield, for example 10 seconds)
        std::thread(&PowerUp::shieldTimer, this).detach();  // Run in separate thread
    }
}

void PowerUp::shieldTimer() {
    int timer = 10;  // Shield duration in seconds
    while (timer > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Shield time remaining: " << timer-- << " seconds\n";
    }
    shieldActive = false;  // Deactivate shield after time runs out
    std::cout << "Shield deactivated!\n";
}