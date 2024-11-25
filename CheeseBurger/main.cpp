#include "NyanCat.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h> 
using namespace std;
int main() {
    char input;
    const int gridRows = 40, gridCols = 60;
    Nyancat nyanCat(-1, gridCols / 2, 1, 1); 
    while (true) {
        system("cls"); 
        nyanCat.draw();
        nyanCat.fall();
        if (_kbhit()) {
            input = _getch(); // Read the key press
            if (input == 'q' || input == 'Q') {
                break; // Quit the game if 'q' is pressed
            }
            nyanCat.move(input);
        }
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << "Game Over!" << endl;
    return 0;
}