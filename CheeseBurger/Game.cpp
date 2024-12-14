#include "Game.h"
#include <iostream>
#include <fstream>   // For file handling
#include <cstdlib>
#include <conio.h>   // For _kbhit() and _getch()
#include <thread>    // For std::this_thread::sleep_for
#include <chrono>    // For std::chrono::milliseconds
#include <limits>    // For std::numeric_limits
#undef max
const int gridCols = 20;
const int gridRows = 20;
const int NUM_SCORES = 5;  // Number of top scores to store
Game::Game() : easyHighScores{ 0 }, mediumHighScores{ 0 }, hardHighScores{ 0 } {
    obj = nullptr;
    loadHighScores();
}
Game::~Game() {
    saveHighScores(); // Ensure high scores are saved when the object is destroyed
}
void Game::displayMainMenu() {
    system("cls");
    obj->printColored("==========================================\n", MAGENTA);
    obj->printColored(" Welcome to Cheeseburger vs. Nyan Cats!\n", GREEN);
    obj->printColored("==========================================\n", MAGENTA);
    obj->printColored("1. Start Game\n", RED);
    obj->printColored("2. Instructions\n", RED);
    obj->printColored("3. High Scores\n", RED);
    obj->printColored("4. Credits\n", RED);
    obj->printColored("5. Exit\n", RED);
    obj->printColored("Select your option: \n", RED);
    obj->printColored("==========================================\n", MAGENTA);
}
void Game::displayLevelMenu() {
    system("cls");
    std::cout << "=============================\n";
    std::cout << " Select Difficulty Level\n";
    std::cout << "=============================\n";
    std::cout << "1. Easy Mode (Regular Nyan Cats)\n";
    std::cout << "2. Medium Mode (Super Nyan Cats)\n";
    std::cout << "3. Hard Mode (Mega Nyan Cats)\n";
    std::cout << "4. Back to Main Menu\n";
    std::cout << "Select your option: ";
}
void Game::displayInstructions() {
    system("cls");
    std::cout << "=============================\n";
    std::cout << " Instructions\n";
    std::cout << "=============================\n";
    std::cout << "1. Use 'A' and 'D' to move left and right.\n";
    std::cout << "2. Avoid getting hit by falling Nyan Cats.\n";
    std::cout << "3. Catch power-ups to boost your score.\n";
    std::cout << "4. Press 'Q' to quit the game.\n";
    std::cout << "4. Press 'ESC' to pause the game.\n";

    std::cout << "=============================\n";
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void Game::displayHighScores() {
    system("cls");
    std::cout << "=============================\n";
    std::cout << " High Scores\n";
    std::cout << "=============================\n";

    std::cout << "Easy Mode:\n";
    for (int i = 0; i < NUM_SCORES; ++i) {
        std::cout << (i + 1) << ". " << easyHighScores[i] << "\n";
    }

    std::cout << "Medium Mode:\n";
    for (int i = 0; i < NUM_SCORES; ++i) {
        std::cout << (i + 1) << ". " << mediumHighScores[i] << "\n";
    }

    std::cout << "Hard Mode:\n";
    for (int i = 0; i < NUM_SCORES; ++i) {
        std::cout << (i + 1) << ". " << hardHighScores[i] << "\n";
    }

    std::cout << "=============================\n";
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void Game::displayCredits() {
    system("cls");
    std::cout << "=============================\n";
    std::cout << " Credits\n";
    std::cout << "=============================\n";
    std::cout << "Muhammad Mudasar Bhatti\n";
    std::cout << "=============================\n";
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void Game::loadHighScores() {
    std::ifstream file("highscores.txt");
    if (file.is_open()) {
        for (int i = 0; i < NUM_SCORES; ++i) {
            file >> easyHighScores[i];
        }
        for (int i = 0; i < NUM_SCORES; ++i) {
            file >> mediumHighScores[i];
        }
        for (int i = 0; i < NUM_SCORES; ++i) {
            file >> hardHighScores[i];
        }
        file.close();
    }
    else {
        // Initialize with default scores if no file is found
        for (int i = 0; i < NUM_SCORES; ++i) {
            easyHighScores[i] = mediumHighScores[i] = hardHighScores[i] = 0;
        }
    }
}
void Game::pauseMenu() {
    system("cls");
    std::cout << "=============================\n";
    std::cout << " Game Paused\n";
    std::cout << "=============================\n";
    std::cout << "1. Resume Game\n";
    std::cout << "2. Exit to Main Menu\n";
    std::cout << "=============================\n";
    std::cout << "Select your option: ";
    int pauseChoice;
    std::cin >> pauseChoice;
    if (pauseChoice == 2) throw std::runtime_error("exit");
}
void Game::saveHighScores() {
    std::ofstream file("highscores.txt");
    if (file.is_open()) {
        // Write mode names before the scores
        file << "Easy Mode: ";
        for (int i = 0; i < NUM_SCORES; ++i) {
            file << easyHighScores[i] << " ";
        }
        file << "\n";

        file << "Medium Mode: ";
        for (int i = 0; i < NUM_SCORES; ++i) {
            file << mediumHighScores[i] << " ";
        }
        file << "\n";

        file << "Hard Mode: ";
        for (int i = 0; i < NUM_SCORES; ++i) {
            file << hardHighScores[i] << " ";
        }
        file << "\n";

        file.close();
        std::cout << "High scores saved successfully!\n";
    }
    else {
        std::cerr << "Error: Could not open highscores.txt for writing!\n";
    }
}
void Game::startGame(int mode) {
    std::string modeName;
    // Determine the mode name based on the selected mode
    switch (mode) {
    case 1:
        modeName = "Easy";
        break;
    case 2:
        modeName = "Medium";
        break;
    case 3:
        modeName = "Hard";
        break;
    default:
        std::cout << "Invalid mode selected, exiting...\n";
        return;
    }
    // Initialize objects for the game
    Cheeseburger burger(-1, 0, gridCols / 2, 1, 3);
    shield powerUp(gridRows, gridCols);
    powerUp.initialize();
    ScoreMultiplier multiplier(gridRows, gridCols);
    multiplier.initialize();
    SpeedBooster speed(gridRows, gridCols);
    speed.initialize();
    // Declare a pointer to the NyanCat object
    NyanCat* nyanCat = nullptr;
    switch (mode) {
    case 1:
        nyanCat = new RegularNyanCat(-1, gridCols / 2, 1, &burger, &powerUp, &multiplier, &speed);
        break;
    case 2:
        nyanCat = new SuperNyanCat(-1, gridCols / 2, 1, &burger, &powerUp, &multiplier, &speed);
        break;
    case 3:
        nyanCat = new MegaNyanCat(-1, gridCols / 2, 1, &burger, &powerUp, &multiplier, &speed);
        break;
    default:
        std::cout << "Invalid mode selected, exiting...\n";
        return;
    }
    nyanCat->initializeCats();
    try {
        while (burger.getLives() > 0) {
            // Clear the screen
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
            // Display game status
            std::cout << "CHEESE BURGER VS NYAN CAT\n";
            nyanCat->displayStatus();
            std::cout << "Mode: " << modeName << "\n"; // Display the mode name
            std::cout << "Speed Boost: " << (burger.isSpeedBoostActive() ? "Active" : "Inactive") << "\n"; // Show speed boost status
            std::cout << "Shield: " << (burger.isShieldActive() ? "Active" : "Inactive") << "\n";         // Show shield status
            // Game mechanics
            nyanCat->draw();
            nyanCat->fall(); // Move objects (nyan cats, power-ups) down
            nyanCat->collide(&burger); // Handle collisions with the cheeseburger
            std::cout << "\n";
            // Handle user input
            if (_kbhit()) { // Check for keyboard input
                char input = _getch();
                if (input == 'q' || input == 'Q') break; // Quit game
                if (input == 27) pauseMenu();           // Pause menu (ESC key)
                nyanCat->move(input);
            }
            // Game delay to control frame rate
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    catch (const std::runtime_error& e) {
        delete nyanCat;
        return;
    }
    // Update high scores after the game ends
    updateHighScores(mode, burger.getScore());
    std::cout << "Game Over!\n";
    delete nyanCat;
    // Pause briefly before returning to the main menu
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
void Game::updateHighScores(int mode, int score) {
    std::array<int, 5>* highScores = nullptr;

    switch (mode) {
    case 1:
        highScores = &easyHighScores;
        break;
    case 2:
        highScores = &mediumHighScores;
        break;
    case 3:
        highScores = &hardHighScores;
        break;
    default:
        std::cerr << "Invalid mode!" << std::endl;
        return;
    }
    // Insert the score in the correct position in the array (maintain sorted order)
    updateScoreList(*highScores, score);  // Passing array by reference
    saveHighScores();  // Save after updating
}
void Game::updateScoreList(std::array<int, 5>& scores, int score) {
    // Insert the score in the correct position in the array (maintain sorted order)
    for (int i = 4; i >= 0; --i) {
        if (score > scores[i]) {
            if (i < 4) {
                scores[i + 1] = scores[i];
            }
            scores[i] = score;
        }
        else {
            break;
        }
    }
}
void Game::run() {
    int mainMenuChoice;
    while (true) {
        displayMainMenu();
        std::cin >> mainMenuChoice;

        switch (mainMenuChoice) {
        case 1: {
            // Start the game and ask for difficulty
            int levelChoice;
            displayLevelMenu();
            std::cin >> levelChoice;
            if (levelChoice >= 1 && levelChoice <= 3) {
                startGame(levelChoice);  // Start the game with selected difficulty
            }
            break;
        }
        case 2:
            displayInstructions();  // Show game instructions
            break;
        case 3:
            displayHighScores();  // Show high scores
            break;
        case 4:
            displayCredits();  // Show credits
            break;
        case 5:
            std::cout << "Exiting the game. Goodbye!\n";
            return;  // Exit the game
        default:
            std::cout << "Invalid option! Please try again.\n";
            break;
        }
    }
}
