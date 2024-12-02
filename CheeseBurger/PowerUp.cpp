#include "Powerup.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Powerup::Powerup(int x, int y, int rows, int cols, Cheeseburger* burger, int speed, int startCol)
    : GameObject(x, y, 4, 2), rows(rows), cols(cols), burger(burger), speed(speed), player_col(startCol),
    shieldRow(0), shieldCol(rand() % cols), boosterRow(0), boosterCol(rand() % cols), multiplierRow(0),
    multiplierCol(rand() % cols), shieldActive(true), boosterActive(true), multiplierActive(true) {
    std::srand(static_cast<unsigned>(std::time(0)));
    for (int k = 0; k < maxCats; ++k) {
        do {
            cats[k].row = std::rand() % rows;
            cats[k].col = std::rand() % cols;
        } while ((cats[k].row == shieldRow && cats[k].col == shieldCol) ||
            (cats[k].row == boosterRow && cats[k].col == boosterCol) ||
            (cats[k].row == multiplierRow && cats[k].col == multiplierCol));
    }
}
bool Powerup::collide(GameObject* other) {
    return false;
}

int Powerup::drawShield() const {
    return 'S';
}

int Powerup::drawBooseter() const {
    return 'B';
}

int Powerup::drawScoreMultiplier() const {
    return 'M';
}

void Powerup::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == rows - 2 && j >= player_col && j < player_col + 4) {
                burger->draw();
            }
            else if (shieldActive && i == shieldRow && j == shieldCol) {
                std::cout << 'S';
            }
            else if (boosterActive && i == boosterRow && j == boosterCol) {
                std::cout << 'B';
            }
            else if (multiplierActive && i == multiplierRow && j == multiplierCol) {
                std::cout << 'M';
            }
            else {
                bool isCatHere = false;
                for (int k = 0; k < maxCats; ++k) {
                    if (cats[k].row == i && cats[k].col == j) {
                        isCatHere = true;
                        std::cout << "N";  // Placeholder for NyanCat
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
void Powerup::move(char dir) {
    // Empty, for now, just to resolve linker error
}
void Powerup::fall() {
    // Update power-ups first
    if (shieldActive) {
        shieldRow++;
        if (shieldRow >= rows) {
            shieldRow = 0;
            shieldCol = rand() % cols;
        }
    }
    if (boosterActive) {
        boosterRow++;
        if (boosterRow >= rows) {
            boosterRow = 0;
            boosterCol = rand() % cols;
        }
    }
    if (multiplierActive) {
        multiplierRow++;
        if (multiplierRow >= rows) {
            multiplierRow = 0;
            multiplierCol = rand() % cols;
        }
    }

    // Now update cats' positions
    for (int k = 0; k < maxCats; ++k) {
        cats[k].row++;  // Move each cat down by one row
        if (cats[k].row >= rows) {  // If the cat reaches the bottom
            cats[k].row = 0;  // Reset the cat to the top
            cats[k].col = rand() % cols;  // Randomize the column
        }
    }
}

int Powerup::getRow()const {
    return rows;
}
int Powerup::getCol()const {
    return cols;
}