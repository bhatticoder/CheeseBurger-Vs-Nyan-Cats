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
            cout << "Invalid choice. Please choose a valid option (1-3)." << endl;
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
    _getch();
}
void displayMenu() {
    cout << "==========================" << endl;
    cout << "      Nyancat Game       " << endl;
    cout << "==========================" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Credits" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-3): ";
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
    _getch();  // Wait for user to press a key
}
void start() {
    const int gridRows = 20, gridCols = 60;
    Nyancat nyanCat(-1, gridCols / 2, 1, 1);
    nyanCat.initializeCats();
    char input;
    while (nyanCat.getLives() > 0) {
        system("cls");
        nyanCat.draw();  // Draw the grid
        nyanCat.fall();  // Update Nyancat falling positions
        nyanCat.collide(nullptr);  // Pass nullptr as no other game objects are involved
        cout << "Lives remaining: " << nyanCat.getLives() << endl;
        if (_kbhit()) {
            input = _getch();
            if (input == 'q' || input == 'Q') {
                gameRunning = false;  // Exit the game loop
                break;
            }
            nyanCat.move(input);  // Move Nyancat based on user input
        }
        this_thread::sleep_for(chrono::milliseconds(30));  // Slow down the game loop
    }
    cout << "Game Over!" << endl;
}