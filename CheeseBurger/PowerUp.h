#ifndef POWERUP_H
#define POWERUP_H

#include "GameObject.h"
#include "Cheeseburger.h"
#include <cstdlib>
#include <thread>
#include <chrono>
class PowerUp : public GameObject {
private:
    int row;  // Current row position
    int col;  // Current column position
    int rows; // Total rows (game boundary)
    int cols; // Total columns (game boundary)
    bool shieldActive = false;
public:
    PowerUp(int totalRows, int totalCols);
    bool collide(GameObject* other)override { return false; }
    void move(char dir)override { cout << "Nothing"; }
    void draw()override { cout << "S"; }
    void initialize();                // Initialize the position of the power-up
    void fall();                      // Move the power-up downward
    bool collidesWith(int catRow, int catCol); // Check if it collides with any object
    int getRow() const;               // Get the current row
    int getCol() const;               // Get the current column
    void activateShield();
    void shieldTimer();
};

#endif
