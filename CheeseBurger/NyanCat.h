#ifndef NYANCAT_H
#define NYANCAT_H

#include "GameObject.h"
#include "Cheeseburger.h"

class Nyancat : public GameObject {
public:
    // Constructor
    Nyancat(int startRow, int startCol, int speed, int level, Cheeseburger* burger);
    // Methods for handling Nyan Cat behavior
    void initializeCats();          // Initialize Nyan Cats
    void fall();                    // Make Nyan Cats fall
    void move(char direction)override;      // Move player
    void collide(GameObject* collideobject)override; // Handle collision
    void draw()override;                    // Draw player and Nyan Cats on screen
    // Getter methods
    int getLives() const;           // Get player lives
    int getRow() const;             // Get player row (not used in this context)
    int getPlayerCol() const;       // Get player column

private:
    // Member variables
    const int rows = 20;               // Number of rows in the game grid
    const int cols = 40;               // Number of columns in the game grid
    const int maxCats = 5;             // Max number of Nyan Cats
    int falling_speed;                 // Speed at which the Nyan Cats fall
    int level;                         // Current game level
    int playerLives;                   // Player's remaining lives
    int player_col;                    // Player's column position
    bool superNyanSpawned;             // Flag to indicate if Super Nyan has spawned
    int superNyanMoved;                // Count of movements for Super Nyan
    Cheeseburger* burger;              // Reference to the Cheeseburger object for score tracking
    struct Cat {
        int row, col;  // Position of each Nyan Cat
    };
    Cat cats[5];   // Array to hold Nyan Cats
};
#endif // NYANCAT_H