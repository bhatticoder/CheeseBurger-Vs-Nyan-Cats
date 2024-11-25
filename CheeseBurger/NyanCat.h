#ifndef NYANCAT_H
#define NYANCAT_H

#include "GameObject.h"
#include <iostream>

class Nyancat : public GameObject {
private:
    struct Cat {
        int row;
        int col;
    };

    static const int maxCats = 3;  // Maximum number of cats allowed
    Cat cats[maxCats];            // Array to store multiple Nyan Cats

    int fallingspeed;             // Falling speed of the cats
    int playerCol;                // Player's current column
    bool isvisible;               // Visibility of the player (if needed)
    int level;                    // Game level

public:
    Nyancat(int startRow, int startCol, int speed, int level);

    // Initialize multiple Nyan Cats with random positions
    void initializeCats();

    // Player movement
    void move(char direction);

    // Update falling position of all Nyan Cats
    void fall();

    // Draw the entire grid (boundaries, player, and Nyan Cats)
    void draw();

    // Getter methods (optional, if needed)
    int getRow() const;          // Get player's row
    int getPlayerCol() const;    // Get player's column
    static const int cols = 60;  // Grid columns (you can adjust based on your game setup)
    static const int rows = 40;  // Grid rows (you can adjust based on your game setup)
};

#endif




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
