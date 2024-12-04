#ifndef GAME_H
#define GAME_H
#include "GameObject.h"
#include "Cheeseburger.h"
#include "NyanCat.h"
#include "PowerUp.h"
#include <string>
#include <array>
#include <stdexcept>

class Game {
private:
    // Array to store last 5 high scores for each difficulty
    std::array<int, 5> easyHighScores;
    std::array<int, 5> mediumHighScores;
    std::array<int, 5> hardHighScores;

    // Helper functions for high score management
    void saveHighScores();
    void loadHighScores();
    void updateScoreList(std::array<int, 5>& scores, int score);

    // Constants for grid dimensions
    static const int gridCols = 20;
    static const int gridRows = 20;

public:
    // Constructor and Destructor
    Game();
    ~Game();

    // Main Menu and Submenus
    void displayMainMenu();
    void displayLevelMenu();
    void displayInstructions();
    void displayHighScores();
    void displayCredits();

    // Game Logic
    void startGame(int mode);
    void pauseMenu();

    // High Score Management
    void updateHighScores(int mode, int score);
    //void setConsoleSize(int width, int height);
    // Game Runner
    void run();
};

#endif // GAME_H