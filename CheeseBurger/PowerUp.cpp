//#include"PowerUp.h"
//Powerup::Powerup(int x, int y, powerup_type type, int duration, Cheeseburger* burger, int rows, int cols)
//    : game_object(x, y, -1, -1), type(type), duration(duration), isactive(false), burger(burger), rows(rows), cols(cols) {}
//
//void Powerup::activate() {
//    if (!isactive) {
//        isactive = true;
//        switch (type) {
//        case Shield:
//            std::cout << "Shield Power-up Activated!" << std::endl;
//            break;
//        case score_multiplier:
//            std::cout << "Score Multiplier Power-up Activated!" << std::endl;
//            break;
//        case speed_boost:
//            std::cout << "Speed Boost Power-up Activated!" << std::endl;
//            break;
//        default:
//            break;
//        }
//    }
//}
//void Powerup::move(char move){}
//// Generalized draw function for all power-ups
//void Powerup::draw() {
//    // Assuming row and col represent the current position of the power-up on the grid
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            if (i == row && j == col) {
//                switch (type) {
//                case Shield:
//                    std::cout << "S";  // Shield power-up represented by 'S'
//                    break;
//                case score_multiplier:
//                    std::cout << "M";  // Score Multiplier represented by 'M'
//                    break;
//                case speed_boost:
//                    std::cout << "B";  // Speed Boost represented by 'B'
//                    break;
//                default:
//                    std::cout << " ";  // Empty space
//                    break;
//                }
//            }
//            else {
//                std::cout << " ";  // Empty space
//            }
//        }
//        std::cout << std::endl;
//    }
//}
//
//void Powerup::fall() {
//    if (!isactive) {
//        row++;
//        if (row >= rows) {  // Check if the power-up has fallen beyond the grid height
//            row = 0;        // Reset position to top
//            col = rand() % cols;  // Randomize horizontal position
//        }
//    }
//}
//
//void Powerup::deactivate() {
//    if (isactive) {
//        isactive = false;
//        switch (type) {
//        case Shield:
//            std::cout << "Shield Power-up Deactivated!" << std::endl;
//            break;
//        case score_multiplier:
//            std::cout << "Score Multiplier Power-up Deactivated!" << std::endl;
//            break;
//        case speed_boost:
//            std::cout << "Speed Boost Power-up Deactivated!" << std::endl;
//            break;
//        default:
//            break;
//        }
//    }
//}
//
//void Powerup::reset() {
//    isactive = false;
//}
//bool Powerup::collide(game_object* other) {
//    // Collision check logic: checks if the power-up is at the player's position
//    if (row == other->getX() && col == other->getY()) {
//        return true;
//    }
//    return false;
//}