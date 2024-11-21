#include "GameObject.h"
GameObject::GameObject(int startRow, int startCol, int rows, int cols)
    : x(0), y(0), row(startRow), col(startCol), rows(rows), cols(cols) {}
// Function to draw a map based on the given rows and cols
void GameObject::draw() {
    // Iterate through the map grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Draw boundaries
            if (i == 0 || i == rows - 1) {  // Top and bottom borders
                cout << "-";  // Horizontal boundary
            }
            else if (j == 0 || j == cols - 1) {  // Left and right borders
                cout << "|";  // Vertical boundary
            }
            // Placeholder for player's position
            else if (i == row && j == col) {  // Draw player at current row, col
                cout << "P";  // Player character
            }
            else {
                cout << " ";  // Empty space
            }
        }
        cout << endl;  // Newline after each row
    }
}
void GameObject::move(char direction) {
    // Move the player based on input character
    if (direction == 'w' || direction == 'W') { // Move up
        if (row > 1) {
            row -= 1;
        }
    }
    else if (direction == 's' || direction == 'S') { // Move down
        if (row < rows - 2) {  // Ensure player does not move out of the lower boundary
            row += 1;
        }
    }
    else if (direction == 'a' || direction == 'A') { // Move left
        if (col > 1) {  // Ensure player does not move out of the left boundary
            col -= 1;
        }
    }
    else if (direction == 'd' || direction == 'D') { // Move right
        if (col < cols - 2) {  // Ensure player does not move out of the right boundary
            col += 1;
        }
    }
    else {
        cout << "Invalid direction input. Use 'w' for up, 's' for down, 'a' for left, 'd' for right.\n";
    }
}
void GameObject::collide(GameObject* other) {

}