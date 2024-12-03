#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>    // For _kbhit() and _getch()
#include <thread>     // For std::this_thread::sleep_for
#include <chrono>     // For std::chrono::milliseconds
const int gridCols = 20; // Set this to the appropriate value
const int gridRows = 20;
Game::Game() : easyHighScore(0), mediumHighScore(0), hardHighScore(0) {}
Game::~Game() {}
void Game::displayMainMenu() {
    system("cls");  // Clear the screen
    std::cout << "=============================\n";
    std::cout << " Welcome to Cheeseburger vs. Nyan Cats!\n";
    std::cout << "=============================\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Instructions\n";
    std::cout << "3. High Scores\n";
    std::cout << "4. Credits\n";
    std::cout << "5. Exit\n";
    std::cout << "Select your option: ";
}
void Game::displayLevelMenu() {
    system("cls");  // Clear the screen
    std::cout << "=============================\n";
    std::cout << " Select Difficulty Level\n";
    std::cout << "=============================\n";
    std::cout << "1. Easy Mode (Regular Nyan Cats)\n";
    std::cout << "2. Medium Mode (Super Nyan Cats)\n";
    std::cout << "3. Mega Mode (Mega Nyan Cats)\n";  // New Mega Mode
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
    std::cout << "=============================\n";
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore();
    std::cin.get();  // Wait for user input
}
void Game::displayHighScores() {
    system("cls");
    std::cout << "=============================\n";
    std::cout << " High Scores\n";
    std::cout << "=============================\n";
    std::cout << "1. Easy Mode High Score: " << easyHighScore << "\n";
    std::cout << "2. Medium Mode High Score: " << mediumHighScore << "\n";
    std::cout << "3. Hard Mode High Score:" << hardHighScore << "\n";
    std::cout << "=============================\n";
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore();
    std::cin.get(); // Wait for user input
}
void Game::displayCredits() {
    system("cls");
    std::cout << "=============================\n";
    std::cout << " Credits\n";
    std::cout << "=============================\n";
    std::cout << "Game Design: Muhammad Mudasar Bhatti\n";
    std::cout << "Programming: Your Name Here\n";
    std::cout << "Art & Graphics: Team Name Here\n";
    std::cout << "=============================\n";
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore();
    std::cin.get();  // Wait for user input
}
void Game::startGame(int mode) {
    // Initialize the Cheeseburger (player) and PowerUp
    Cheeseburger burger(-1, 0, gridCols / 2, 1, 3); // Position the player in the middle
    PowerUp powerUp(gridRows, gridCols);             // Create the PowerUp instance
    powerUp.initialize();                            // Initialize PowerUp object

    // Create a pointer for the NyanCat
    NyanCat* nyanCat = nullptr;

    // Initialize the NyanCat based on the selected mode
    switch (mode) {
    case 1:
        nyanCat = new RegularNyanCat(-1, gridCols / 2, 1, &burger, &powerUp);
        std::cout << "Easy mode selected! Regular Nyan Cats are active.\n";
        break;
    case 2:
        nyanCat = new SuperNyanCat(-1, gridCols / 2, 1, &burger, &powerUp);
        std::cout << "Medium mode selected! Super Nyan Cats are active.\n";
        break;
    case 3:
        nyanCat = new MegaNyanCat(-1, gridCols / 2, 1, &burger, &powerUp);
        std::cout << "Hard mode selected! Mega Nyan Cats are active.\n";
        break;
    default:
        std::cout << "Invalid mode selected, exiting...\n";
        return;
    }

    nyanCat->initializeCats();  // Initialize the falling Nyan Cats

    char input;
    while (burger.getLives() > 0) {
        system("cls");  // Clear the console screen for the next frame

        nyanCat->draw();   // Draw the NyanCats and other elements (like power-ups)
        nyanCat->fall();   // Update the position of NyanCats

        // Check for collision with Cheeseburger, apply shield protection if needed
        nyanCat->collide(&burger);

        // Display player lives and score
        std::cout << "Lives remaining: " << burger.getLives() << std::endl;
        std::cout << "Score: " << burger.getScore() << std::endl;

        // Display shield status
        if (burger.isShieldActive()) {
            std::cout << "Shield Active!\n";
        }

        // Handle user input for movement
        if (_kbhit()) {
            input = _getch();
            if (input == 'q' || input == 'Q') {
                break;  // Quit the game if 'Q' is pressed
            }
            nyanCat->move(input);  // Move the Cheeseburger (player)
        }

        // Implement power-up collision (if shield power-up is collected)
        if (burger.isShieldActive()) {
            powerUp.activateShield();
        }
    }

    // Update the corresponding high score
    updateHighScore(mode, burger.getScore());

    std::cout << "Game Over!" << std::endl;

    // Free dynamically allocated memory
    delete nyanCat;  // Free memory for the NyanCat

    // Give the player a moment to read the game over message
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

// Function to update high scores based on the mode
void Game::updateHighScore(int mode, int score) {
    switch (mode) {
    case 1:
        if (score > easyHighScore) {
            easyHighScore = score;
            std::cout << "New Easy Mode High Score: " << easyHighScore << "!\n";
        }
        break;
    case 2:
        if (score > mediumHighScore) {
            mediumHighScore = score;
            std::cout << "New Medium Mode High Score: " << mediumHighScore << "!\n";
        }
        break;
    case 3:
        if (score > hardHighScore) {
            hardHighScore = score;
            std::cout << "New Hard Mode High Score: " << hardHighScore << "!\n";
        }
        break;
    default:
        std::cout << "Invalid mode for updating high score!\n";
        break;
    }
}


void Game::run() {
    int mainChoice = 0;
    while (true) {
        displayMainMenu();
        std::cin >> mainChoice;
        if (mainChoice == 1) {
            int levelChoice = 0;
            while (true) {
                displayLevelMenu();
                std::cin >> levelChoice;
                if (levelChoice == 1) {
                    startGame(1);  // Easy mode
                    break;
                }
                else if (levelChoice == 2) {
                    startGame(2);  // Medium mode
                    break;
                }
                else if (levelChoice == 3) {
                    startGame(3);  // Mega mode
                    break;
                }
                else if (levelChoice == 4) {
                    break;  // Back to main menu
                }
                else {
                    std::cout << "Invalid option. Please try again.\n";
                }
            }
        }
        else if (mainChoice == 2) {
            displayInstructions();
        }
        else if (mainChoice == 3) {
            displayHighScores();
        }
        else if (mainChoice == 4) {
            displayCredits();
        }
        else if (mainChoice == 5) {
            std::cout << "Thanks for playing! Goodbye.\n";
            break;
        }
        else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}