#ifndef GAME_H
#define GAME_H
#include "Nyancat.h"
#include "Cheeseburger.h"
class Game {
private:
    int easyHighScore;   // High score for Easy mode
    int mediumHighScore; // High score for Medium mode
public:
    Game(); // Constructor
    void run(); // Main game loop
    void displayMainMenu();
    void displayLevelMenu();
    void displayInstructions();
    void displayHighScores();
    void displayCredits();
    void startGame(bool isHardMode);
};

#endif