#include "Nyancat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <thread>
#include <chrono>
// NyanCat constructor
NyanCat::NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger)
    : GameObject(startRow, startCol, 20, 40), falling_speed(speed), playerLives(3),
    player_col(startCol), burger(burger) {}
int NyanCat::getLives() const {
    return playerLives;
}
int NyanCat::getRow() const {
    return -1;  // Not applicable, override in child class
}
int NyanCat::getPlayerCol() const {
    return player_col;
}
void NyanCat::initializeCats() {
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row = -1;  // Start from the top
        cats[i].col = rand() % (cols - 2) + 1;  // Random column
    }
}
void NyanCat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
// RegularNyanCat implementation
RegularNyanCat::RegularNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger)
    : NyanCat(startRow, startCol, speed, burger) {}
void RegularNyanCat::fall() {
    // Regular Nyan Cat behavior: just fall with the regular speed
    for (int i = 0; i < maxCats; ++i) {
        // Check if the cat has reached the bottom of the screen
        if (cats[i].row >= rows - 1) {
            // Reset the position of the Nyan Cat if it reaches the bottom
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;  // Random column within screen bounds
            if (burger) {
                burger->updateScore(10);  // Update the score for each Nyan Cat
            }
        }
        else {
            cats[i].row += 1;  // Move the Nyan Cat down
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
bool RegularNyanCat::collide(GameObject* collideobject) {
    // Check for collision with the Cheeseburger (player)
    for (int i = 0; i < maxCats; ++i) {
        // Check if the cat's position overlaps with the player's position
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            if (collideobject) {
                Cheeseburger* burger = dynamic_cast<Cheeseburger*>(collideobject);
                if (burger) {
                    burger->collide(this); // Trigger cheeseburger's collision logic
                }
            }\
                cats[i].row = -1; // Start falling again from the top
        }
    }
    return false; // Default return value for no collision
}
void RegularNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                burger->draw();
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";
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
void RegularNyanCat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Super Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
// SuperNyanCat implementation
SuperNyanCat::SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger)
    : NyanCat(startRow, startCol, speed, burger) {}
void SuperNyanCat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;  // Random column for the Super Nyan Cat
            if (burger) {
                burger->updateScore(15);  // Update score more for Super Nyan Cat (can be adjusted)
            }
        }
        else {
            cats[i].row += 1;  // Faster falling speed for Super Nyan Cat
        }
    }
}
bool SuperNyanCat::collide(GameObject* collideobject) {
    // Check for collision with the Cheeseburger (player)
    for (int i = 0; i < maxCats; ++i) {
        // Check if the cat's position overlaps with the player's position
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            if (collideobject) {
                Cheeseburger* burger = dynamic_cast<Cheeseburger*>(collideobject);
                if (burger) {
                    burger->collide(this); // Trigger cheeseburger's collision logic
                }
            }
            // Reset the cat to the top after collision
            cats[i].row = -1; // Start falling again from the top
        }
    }
    return false; // Default return value for no collision
}
void SuperNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                burger->draw();
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";
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
void SuperNyanCat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Mega Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
MegaNyanCat::MegaNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger)
    : NyanCat(startRow, startCol, speed, burger) {}
void MegaNyanCat::fall() {
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;  // Random column for the Super Nyan Cat
            if (burger) {
                burger->updateScore(15);  // Update score more for Super Nyan Cat (can be adjusted)
            }
        }
        else {
            cats[i].row += 1;  // Faster falling speed for Super Nyan Cat
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
bool MegaNyanCat::collide(GameObject* collideobject) {
    // Check for collision with the Cheeseburger (player)
    for (int i = 0; i < maxCats; ++i) {
        // Check if the cat's position overlaps with the player's position
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            if (collideobject) {
                Cheeseburger* burger = dynamic_cast<Cheeseburger*>(collideobject);
                if (burger) {
                    burger->collide(this); // Trigger cheeseburger's collision logic
                }
            }
            // Reset the cat to the top after collision
            cats[i].row = -1; // Start falling again from the top
            cats[i].col = rand() % (cols - 2) + 1;
        }
    }
    teleport();
    return false; // Default return value for no collision
}
void MegaNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                burger->draw();
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";
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
void MegaNyanCat::move(char direction) {
    if (direction == 'a' || direction == 'A') {
        if (player_col > 1) player_col--;
    }
    else if (direction == 'd' || direction == 'D') {
        if (player_col < cols - 4) player_col++;
    }
}
void MegaNyanCat::teleport() {
    // Teleport Super Nyan to a random column
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= 0) {  // Ensure Super Nyan is active (not offscreen)
            cats[i].col = rand() % (cols - 2) + 1;  // Random column within screen bounds
        }
    }
}