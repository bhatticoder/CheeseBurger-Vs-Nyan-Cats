#include "PowerUp.h"
PowerUp::PowerUp(int totalRows, int totalCols)
    : GameObject(-1, 0, totalRows, totalCols), // Pass initial positions and dimensions to GameObject
    rows(totalRows), cols(totalCols), row(-1), col(0) {}
void PowerUp::initialize() {
    row = -1;                        // Start above the screen
    col = rand() % (cols - 2) + 1;   // Randomize the column
}
int PowerUp::getRow() const {
    return row;
}
int PowerUp::getCol() const {
    return col;
}
void PowerUp::fall() {
    if (row == rows + 6) {  // Adjust condition to account for the last playable row
        row = -1;  // Reset to the top once it reaches the bottom
        col = rand() % (cols - 2) + 1;  // Random horizontal position
    }
    else {
        row++;  // Move down by one row
    }
}
bool PowerUp::collidesWith(int playerRow, int playerCol) {
    // Check if the shield's position overlaps with the player's position
    return this->row == playerRow &&
        this->col >= playerCol &&
        this->col < playerCol + 4;
}
void PowerUp::activateShield(Cheeseburger* burger) {
    if (!shieldActive) {
        shieldActive = true;
        std::cout << "Shield Activated! Lives are protected for 10 seconds.\n";
        // Start the shield timer in a separate thread
        //std::thread(&Cheeseburger::updateShield, burger).detach();  // Correctly pass the Cheeseburger pointer
    }
}
void PowerUp::drawMultiplier() {
    cout << "M";
}