#include "PowerUp.h"
shield::shield(int totalRows, int totalCols)
    : GameObject(-1, 0, totalRows, totalCols), // Pass initial positions and dimensions to GameObject
    rows(totalRows), cols(totalCols), row(-1), col(0) {
}
void shield::initialize() {
    row = -1;                        // Start above the screen
    col = rand() % 3 * (cols - 2) + 1;   // Randomize the column
}
int shield::getRow() const {
    return row;
}
int shield::getCol() const {
    return col;
}
void shield::fall() {
    if (row == rows + 6) {  // Adjust condition to account for the last playable row
        row = -1;  // Reset to the top once it reaches the bottom
        col = rand() % (cols - 2) + 1;  // Random horizontal position
    }
    else {
        row++;  // Move down by one row
    }
}
bool shield::collidesWith(int playerRow, int playerCol) {
    // Check if the shield's position overlaps with the player's position
    return this->row == playerRow &&
        this->col >= playerCol &&
        this->col < playerCol + 4;
}
void shield::activateShield(Cheeseburger* burger) {
    if (!burger->isShieldActive()) {
        burger->activateShield(); // Activate shield on burger
    }
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
ScoreMultiplier::ScoreMultiplier(int totalRows, int totalCols)
    : GameObject(-1, 0, totalRows, totalCols), row(-1), col(0), active(true) {
    // Initial setup for the multiplier
}
void ScoreMultiplier::initialize() {
    row = -1;                      // Start above the screen
    col = rand() % (cols - 2) + 1; // Randomize the column
}
void ScoreMultiplier::fall() {
    if (row == rows + 6) {  // Once it reaches the bottom, reset
        row = -1;
        col = rand() % (cols - 2) + 1;  // Random horizontal position
    }
    else {
        row++;  // Move down by one row
    }
}
bool ScoreMultiplier::collidesWith(int playerRow, int playerCol) {
    // Check if the multiplier's position overlaps with the player's position
    return this->row == playerRow &&
        this->col >= playerCol &&
        this->col < playerCol + 4;
}
void ScoreMultiplier::draw() {
    printColored("M", RED);  // Represent the multiplier (M for multiplier)
}
int ScoreMultiplier::getRow() const {
    return row;
}
int ScoreMultiplier::getCol() const {
    return col;
}
//////////////////////////////////////////////////////////////
SpeedBooster::SpeedBooster(int totalRows, int totalCols)
    : GameObject(-1, rand() % (totalCols - 2) + 1, totalRows, totalCols),
    row(-1), col(rand() % (totalCols - 2) + 1) {
}

void SpeedBooster::initialize() {
    row = -1;                      // Start above the screen
    col = rand() % (cols - 2) + 1; // Randomize the column
}

void SpeedBooster::fall() {
    if (row >= rows + 6) {  // Once it reaches the bottom, reset
        row = -1;                      // Reset to the top
        col = rand() % (cols - 2) + 1; // Randomize horizontal position
    }
    else {
        row++;  // Move down by one row
    }
}
// Handle collision with the Cheeseburger (burger) and boost its speed
bool SpeedBooster::collidesWith(int playerRow, int playerCol) {
    // Check if the booster's position overlaps with the player's position
    return this->row == playerRow &&
        this->col >= playerCol &&
        this->col < playerCol + 4;
}

void SpeedBooster::activateSpeedBoost(Cheeseburger* burger) {
    if (burger) {
        burger->activateSpeedBoost(); // Temporarily boost speed
        std::cout << "Speed Booster Activated! Burger speed increased temporarily.\n";
    }
}
void SpeedBooster::move(char direction) {
    // Ensure that burger is not null
    Cheeseburger* burger = nullptr;
    if (burger == nullptr) {
        std::cerr << "Error: Cheeseburger is not initialized." << std::endl;
        return;  // Exit if burger is not set
    }
    // Calculate move distance based on shield status
    int moveDistance = (burger->isShieldActive() ? 4 : 1);  // If shield is active, move 4; else move 1.
    if (direction == 'a' || direction == 'A') {
        // Move left by moveDistance but ensure it doesn't go out of bounds
        burger->setPlayerCol(std::max(0, burger->getPlayerCol() - moveDistance));
        burger->setPlayerCol(4);
    }
    else if (direction == 'd' || direction == 'D') {
        // Move right by moveDistance but ensure it doesn't go out of bounds
        burger->setPlayerCol(std::min(cols - 1, burger->getPlayerCol() + moveDistance));
        burger->setPlayerCol(4);
    }
}
void SpeedBooster::draw() {
    printColored("B", CYAN);  // Represent the speed booster (B for booster)
}
int SpeedBooster::getRow() const {
    return row;
}

int SpeedBooster::getCol() const {
    return col;
}