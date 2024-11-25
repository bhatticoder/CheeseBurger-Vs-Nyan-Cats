#include "GameObject.h"
#include <iostream>
using namespace std;
// Constructor to initialize the GameObject
GameObject::GameObject(int startRow, int startCol, int rows, int cols)
    : x(x), y(y), row(startRow), col(startCol), rows(rows), cols(cols) {}
//void GameObject::draw() {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            // Draw boundaries
//            if (i == 0 || i == rows - 1) {  // Top and bottom borders
//                cout << "=";  // Horizontal boundary
//            }
//            else if (j == 0 || j == cols - 1) {  // Left and right borders
//                cout << "||";  // Vertical boundary
//            }
//            // Draw player
//            else if (i == rows - 2 && j == col / 2) {  // Player at the bottom center
//                cout << "P";  // Player character
//            }
//            else {
//                cout << " "; // Empty space
//            }
//        }
//        cout << endl;
//    }
//}
//void GameObject::move(char direction) {
//    if (direction == 'a' || direction == 'A') {  // Move left
//        if (col > 1) {  // Ensure player does not move out of bounds
//            col -= 1;
//        }
//    }
//    else if (direction == 'd' || direction == 'D') {  // Move right
//        if (col < cols - 2) {  // Ensure player does not move out of bounds
//            col += 1;
//        }
//    }
//}