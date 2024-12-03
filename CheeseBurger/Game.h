#ifndef GAME_H
#define GAME_H

#include <string>
#include "NyanCat.h"
#include "GameObject.h"
#include "Cheeseburger.h"
#include "PowerUp.h"
const int gridCols = 20;
const int gridRows = 20;
class Game {
public:
    Game();
    ~Game();
    void run();
private:
    int easyHighScore;
    int mediumHighScore;
    int hardHighScore;
    void displayMainMenu();
    void displayLevelMenu();
    void displayInstructions();
    void displayHighScores();
    void startGame(int mode);
    void displayCredits();
    void pauseMenu();
    void updateHighScore(int mode, int score);
};
#endif  // GAME_H