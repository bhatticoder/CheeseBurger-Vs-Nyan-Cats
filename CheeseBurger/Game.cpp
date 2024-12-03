#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>    // For _kbhit() and _getch()
#include <thread>     // For std::this_thread::sleep_for
#include <chrono>     // For std::chrono::milliseconds
Game::Game() : easyHighScore(0), mediumHighScore(0), hardHighScore(0) {}
Game::~Game() {}
void Game::displayMainMenu() {
    system("cls");
    std::cout << "==========================================\n";
    std::cout << " Welcome to Cheeseburger vs. Nyan Cats!\n";
    std::cout << "==========================================\n";
    std::cout << "1. Start Game\n";
    std::cout << "2. Instructions\n";
    std::cout << "3. High Scores\n";
    std::cout << "4. Credits\n";
    std::cout << "5. Exit\n";
    std::cout << "Select your option: ";
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
    std::cout << "1. Easy Mode: " << easyHighScore << "\n";
    std::cout << "2. Medium Mode: " << mediumHighScore << "\n";
    std::cout << "3. Hard Mode: " << hardHighScore << "\n";
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
    std::cout << "Game Design: Muhammad Mudasar Bhatti\n";
    std::cout << "Programming: Your Name Here\n";
    std::cout << "Art & Graphics: Team Name Here\n";
    std::cout << "=============================\n";
    std::cout << "Press Enter to return to the main menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void Game::startGame(int mode) {
    Cheeseburger burger(-1, 0, gridCols / 2, 1, 3);
    PowerUp powerUp(gridRows, gridCols);
    powerUp.initialize();
    NyanCat* nyanCat = nullptr;
    switch (mode) {
    case 1: nyanCat = new RegularNyanCat(-1, gridCols / 2, 1, &burger, &powerUp); break;
    case 2: nyanCat = new SuperNyanCat(-1, gridCols / 2, 1, &burger, &powerUp); break;
    case 3: nyanCat = new MegaNyanCat(-1, gridCols / 2, 1, &burger, &powerUp); break;
    default:
        std::cout << "Invalid mode selected, exiting...\n";
        return;
    }
    nyanCat->initializeCats();
    try {
        while (burger.getLives() > 0) {
            system("cls");
            nyanCat->draw();
            nyanCat->fall();
            nyanCat->collide(&burger);

            std::cout << "Lives: " << burger.getLives() << " | Score: " << burger.getScore();
            if (burger.isShieldActive()) {
                std::cout << " | Shield Active (" << burger.updateShield() << " sec)";
            }
            std::cout << "\n";

            if (_kbhit()) {
                char input = _getch();
                if (input == 'q' || input == 'Q') break;
                if (input == 27) pauseMenu();
                else nyanCat->move(input);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    catch (const std::runtime_error& e) {
        delete nyanCat;
        return;
    }
    updateHighScore(mode, burger.getScore());
    std::cout << "Game Over!\n";
    delete nyanCat;
    std::this_thread::sleep_for(std::chrono::seconds(2));
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
void Game::updateHighScore(int mode, int score) {
    int& highScore = (mode == 1) ? easyHighScore :
        (mode == 2) ? mediumHighScore :
        (mode == 3) ? hardHighScore : throw std::invalid_argument("Invalid mode");

    if (score > highScore) {
        highScore = score;
        std::cout << "New High Score for Mode " << mode << ": " << highScore << "!\n";
    }
}
void Game::run() {
    int choice;
    while (true) {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            int levelChoice;
            do {
                displayLevelMenu();
                std::cin >> levelChoice;
            } while (levelChoice < 1 || levelChoice > 4);

            if (levelChoice != 4) startGame(levelChoice);
            break;
        case 2: displayInstructions(); break;
        case 3: displayHighScores(); break;
        case 4: displayCredits(); break;
        case 5: std::cout << "Thanks for playing! Goodbye.\n"; return;
        default: std::cout << "Invalid option. Try again.\n"; break;
        }
    }
}