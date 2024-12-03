#include "Nyancat.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <thread>
#include <chrono>
NyanCat::NyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp)
    : GameObject(startRow, startCol, 25, 50),
      falling_speed(speed),
      playerLives(3),
      player_row(startRow),
      player_col(startCol),
      burger(burger),
      powerUp(powerUp) {
    initializeCats();
    powerUp->initialize();  // Initialize the shield position
}
int NyanCat::getLives() const {
    return playerLives;
}
int NyanCat::getRow() const {
    return -1;  // Not applicable
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
bool NyanCat::collide(GameObject* collideobject) {
    // Check if the NyanCat collides with the Cheeseburger
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row == rows - 2 && cats[i].col >= player_col && cats[i].col < player_col + 4) {
            if (collideobject) {
                Cheeseburger* burger = dynamic_cast<Cheeseburger*>(collideobject);
                if (burger) {
                    burger->collide(this);
                }
            }
            cats[i].row = -1;  // Restart falling
        }
    }
    return false;
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Regular Nyan Cat Implementation|////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
RegularNyanCat::RegularNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp)
    : NyanCat(startRow, startCol, speed, burger, powerUp) {
    // Any additional initialization for RegularNyanCat
}
void RegularNyanCat::fall() {
    // Nyan Cats fall
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;
            if (burger) {
                burger->updateScore(10);  // Update the score for each Nyan Cat
            }
        }
        else {
            cats[i].row++;
        }
    }
    powerUp->fall();
    for (int i = 0; i < maxCats; ++i) {
        if (powerUp->collidesWith(cats[i].row, cats[i].col)) {
            powerUp->initialize();
            break;
        }
    }
}
bool RegularNyanCat::collide(GameObject* collideobject) {
    if (powerUp->collidesWith(rows - 2, player_col)) {  // Burger is on the second last row
        powerUp->activateShield(burger);  // Activate the shield
        powerUp->initialize();     // Reset the shield position
        return false;              // No further collision effects
    }
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
            cats[i].row = -1; // Start falling again from the top
        }
    }
    return false; // Default return value for no collision
}
void RegularNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) {
                std::cout << "=";  // Horizontal boundary
            }
            else if (j == 0 || j == cols - 1) {
                std::cout << "||";  // Vertical boundary
            }
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                burger->draw();  // Draw the burger
            }
            else if (i == powerUp->getRow() && j == powerUp->getCol()) {
                powerUp->draw();
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        std::cout << "N";  // Draw a Nyan Cat
                        isCatHere = true;
                        break;
                    }
                }
                if (!isCatHere) std::cout << " ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Super Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
SuperNyanCat::SuperNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp)
    : NyanCat(startRow, startCol, speed, burger, powerUp) {
    // Any additional initialization for SuperNyanCat
}
void SuperNyanCat::fall() {
    // Nyan Cats fall
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;
            if (burger) {
                burger->updateScore(10);  // Update the score for each Nyan Cat
            }
        }
        else {
            cats[i].row++;
        }
    }
    // Shield (PowerUp) falls
    powerUp->fall();
    // Ensure no collision between PowerUp and Nyan Cats
    for (int i = 0; i < maxCats; ++i) {
        if (powerUp->collidesWith(cats[i].row, cats[i].col)) {
            powerUp->initialize();
            break;
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
            if (i == 0 || i == rows - 1) {
                std::cout << "=";
            }
            else if (j == 0 || j == cols - 1) {
                std::cout << "||";
            }
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                burger->draw();
            }
            else if (i == powerUp->getRow() && j == powerUp->getCol()) {
                powerUp->draw();
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
                if (!isCatHere) std::cout << " ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////|Mega Nyan Cat Implementation|///////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
MegaNyanCat::MegaNyanCat(int startRow, int startCol, int speed, Cheeseburger* burger, PowerUp* powerUp)
    : NyanCat(startRow, startCol, speed, burger, powerUp) {
    // Any additional initialization for MegaNyanCat
}
void MegaNyanCat::fall() {
    // Nyan Cats fall
    for (int i = 0; i < maxCats; ++i) {
        if (cats[i].row >= rows - 1) {
            cats[i].row = -1;
            cats[i].col = rand() % (cols - 2) + 1;
            if (burger) {
                burger->updateScore(10);  // Update the score for each Nyan Cat
            }
        }
        else {
            cats[i].row++;
        }
    }
    // Shield (PowerUp) falls
    powerUp->fall();
    // Ensure no collision between PowerUp and Nyan Cats
    for (int i = 0; i < maxCats; ++i) {
        if (powerUp->collidesWith(cats[i].row, cats[i].col)) {
            powerUp->initialize();
            break;
        }
    }
}
void MegaNyanCat::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1) {
                std::cout << "=";
            }
            else if (j == 0 || j == cols - 1) {
                std::cout << "||";
            }
            else if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                burger->draw();
            }
            else if (i == powerUp->getRow() && j == powerUp->getCol()) {
                powerUp->draw();
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
                if (!isCatHere) std::cout << " ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
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

void MegaNyanCat::teleport() {
    // Teleport to random position
    for (int i = 0; i < maxCats; ++i) {
        cats[i].row = rand() % (rows - 1);
        cats[i].col = rand() % (cols - 1);
    }
}