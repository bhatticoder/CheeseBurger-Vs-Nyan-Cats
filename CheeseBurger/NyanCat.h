#ifndef NYANCAT_H
#define NYANCAT_H

#include "GameObject.h"  // Assuming GameObject class exists and is included

class Nyancat : public GameObject {
public:
    // Constructor declaration
    Nyancat(int startRow, int startCol, int speed, int level);

    // Methods
    void move(char direction);  // Move the player based on user input (left or right)
    void fall();  // Nyan Cat falling logic
    void draw();  // Draw the grid and objects (player and Nyan Cat)

private:
    int row;           // Nyan Cat's row position
    int col;           // Nyan Cat's column position
    int playerCol;     // Player's column position (separate from Nyan Cat)
    int fallingspeed;  // Speed at which Nyan Cat falls
    bool isvisible;    // Whether Nyan Cat is visible or not
    int level;         // Level (could be used later for game logic)

    static const int rows = 40;  // Grid rows (you can adjust based on your game setup)
    static const int cols = 60;  // Grid columns (you can adjust based on your game setup)
};

#endif // NYANCAT_H

//// advance nyan cat variants
//class Super_nyancat : public Nyancat
//{
//public:
//	Super_nyancat(int x, int y, int speed);
//	void fall() override;
//	void move() override;
//};
//
//class Mega_nyancat : public Nyancat
//{
//public:
//	Mega_nyancat(int x, int y, int speed);
//	void fall() override;
//	void move() override;
//};
