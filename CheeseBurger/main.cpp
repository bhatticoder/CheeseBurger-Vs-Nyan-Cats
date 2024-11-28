#include "NyanCat.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h> 
using namespace std;
void credits();
void displayMenu();
void showInstructions();
void start();
bool gameRunning = true;
int main() {
    int choice;
    while (gameRunning) {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1: {
            start();
            break;
        }
        case 2: {
            showInstructions();
            break;
        }
        case 3: {
            credits();
            break;
        }
        case 4: {
            cout << "Exiting game. Goodbye!" << endl;
            gameRunning = false;  // Exit the menu loop and end the game
            break;
        }
        default:
            cout << "Invalid choice. Please choose a valid option (1-4)." << endl;
            break;
        }
    }
    return 0;
}
void credits() {
    cout << "================================================" << endl;
    cout << "Created By: " << endl;
    cout << "Muhammad Talha.\t\t Roll# 23F-0511 " << endl;
    cout << "Abdul Rafay.\t\t Roll# 23F-0591 " << endl;
    cout << "Press any key to return to the menu..." << endl;
    cout << "================================================" << endl;
}
void displayMenu() {
    cout << "==========================" << endl;
    cout << "      Nyancat Game       " << endl;
    cout << "==========================" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Credits" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}
void showInstructions() {
    cout << "\nInstructions:" << endl;
    cout << "==========================================================================" << endl;
    cout << "1. Use 'A' to move left and 'D' to move right." << endl;
    cout << "2. Avoid falling Nyancats (represented as 'N')." << endl;
    cout << "3. Press 'Q' to quit the game at any time." << endl;
    cout << "4. You start with 3 lives, which decrease on collisions." << endl;
    cout << "Press any key to return to the menu..." << endl;
    cout << "==========================================================================" << endl;
}
void start() {
    const int gridRows = 20, gridCols = 60;
    Cheeseburger burger(0, gridCols / 2, 1, 3); // Initialize Cheeseburger
    Nyancat nyanCat(-1,gridCols / 2, 1, 1,&burger); // Pass Cheeseburger to Nyancat
    nyanCat.initializeCats();
    char input;
    while (nyanCat.getLives() > 0) {
        system("cls");
        nyanCat.draw();          // Draw the grid
        nyanCat.fall();          // Update Nyancat falling positions
        nyanCat.collide(nullptr); // Handle collisions (if applicable)
        // Print player lives and score
        std::cout << "Lives remaining: " << nyanCat.getLives() << std::endl;
        std::cout << burger << std::endl; // Use overloaded << to print score
        if (_kbhit()) {
            input = _getch();
            if (input == 'q' || input == 'Q') {
                break; // Exit the game loop
            }
            nyanCat.move(input); // Move player based on input
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Slow down the game loop
    }
    std::cout << "Game Over!" << std::endl;
}
