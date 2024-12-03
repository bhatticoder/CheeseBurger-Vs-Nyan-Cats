#ifndef POWERUP_H
#define POWERUP_H

#include "GameObject.h"
#include "Cheeseburger.h"
#include <cstdlib>
#include <thread>
#include <chrono>
class shield : public GameObject {
private:
    int row;  // Current row position
    int col;  // Current column position
    int rows; // Total rows (game boundary)
    int cols; // Total columns (game boundary)
    bool shieldActive = false;
public:
    shield(int totalRows, int totalCols);
    bool collide(GameObject* other)override { return false; }
    void move(char dir)override { cout << "Nothing"; }
    void draw()override { printColored("S", GREEN); }
    void initialize();                // Initialize the position of the power-up
    void fall();                      // Move the power-up downward
    bool collidesWith(int catRow, int catCol); // Check if it collides with any object
    int getRow() const;               // Get the current row
    int getCol() const;               // Get the current column
    void activateShield(Cheeseburger* burger);
    //void shieldTimer();
};
class ScoreMultiplier : public GameObject {
private:
    int row, col;
    bool active;
public:
    ScoreMultiplier(int totalRows, int totalCols);
    void initialize();   // Initialize multiplier
    void fall();         // Make the multiplier fall down
    bool collidesWith(int playerRow, int playerCol);  // Check for collision
    void draw() override; // Draw the multiplier
    int getRow() const;
    int getCol() const;
    bool collide(GameObject* other) override { return false; }
    void move(char dir) override { cout << ""; }
};
class SpeedBooster : public GameObject {
private:
    int row, col;
public:
    SpeedBooster(int totalRows, int totalCols);
    void initialize();
    void fall();
    int getRow()const;
    int getCol()const;
    bool collidesWith(int playerRow, int playerCol);
    void activateSpeedBoost(Cheeseburger* burger);
    bool collide(GameObject* burger)override { return false; }
    void move(char dir) override;
    void draw() override;           // Draw "B" for Speed Booster
};
#endif
