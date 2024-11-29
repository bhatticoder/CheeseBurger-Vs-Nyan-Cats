#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>    // For _kbhit() and _getch()
#include <thread>     // For std::this_thread::sleep_for
#include <chrono>     // For std::chrono::milliseconds
const int gridCols = 20; // Set this to the appropriate value
Game::Game() : easyHighScore(0), mediumHighScore(0),hardHighScore(0) {
    // Additional initialization if needed
}
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
    Cheeseburger burger(0, gridCols / 2, 1, 3);  // Initialize Cheeseburger (player)
    NyanCat* nyanCat = nullptr;

    if (mode == 1) {
        nyanCat = new RegularNyanCat(-1, gridCols / 2, 1, &burger);  // Easy mode
        std::cout << "Easy mode selected! Regular Nyan Cats are active.\n";
    }
    else if (mode == 2) {
        nyanCat = new SuperNyanCat(-1, gridCols / 2, 1, &burger);  // Medium mode
        std::cout << "Medium mode selected! Super Nyan Cats are active.\n";
    }
    else if (mode == 3) {
        nyanCat = new MegaNyanCat(-1, gridCols / 2, 1, &burger);  // Mega mode
        std::cout << "Mega mode selected! Mega Nyan Cats are active.\n";
    }

    nyanCat->initializeCats();  // Initialize the falling cats
    char input;
    while (nyanCat->getLives() > 0) {
        system("cls");
        nyanCat->draw();
        nyanCat->fall();
        nyanCat->collide(nullptr);
        // Display player lives and score
        std::cout << "Lives remaining: " << nyanCat->getLives() << std::endl;
        std::cout << burger << std::endl;

        if (_kbhit()) {
            input = _getch();
            if (input == 'q' || input == 'Q') {
                break;
            }
            nyanCat->move(input);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Update the corresponding high score
    if (mode == 1) {
        if (burger.getScore() > easyHighScore) {
            easyHighScore = burger.getScore();
            std::cout << "New Easy Mode High Score: " << easyHighScore << "!\n";
        }
    }
    else if (mode == 2) {
        if (burger.getScore() > mediumHighScore) {
            mediumHighScore = burger.getScore();
            std::cout << "New Medium Mode High Score: " << mediumHighScore << "!\n";
        }
    }
    else if (mode == 3) {
        if (burger.getScore() > hardHighScore) {
            hardHighScore = burger.getScore();
            std::cout << "New Medium Mode High Score: " << hardHighScore << "!\n";
        }
    }
    std::cout << "Game Over!" << std::endl;
    delete nyanCat;  // Free memory
    std::this_thread::sleep_for(std::chrono::seconds(2));
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