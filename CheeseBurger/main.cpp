#include "NyanCat.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h> 
using namespace std;
int main() {
    const int gridRows = 30, gridCols = 60;  
    Nyancat nyanCat(-1, gridCols / 2, 1, 1); 
    nyanCat.initializeCats(); 
    char input;
    while (true) {
        system("cls"); 
        nyanCat.draw(); 
        nyanCat.fall();  
        if (_kbhit()) {
            input = _getch(); 
            if (input == 'q' || input == 'Q') {
                break;  
            }
            nyanCat.move(input);  
        }
        this_thread::sleep_for(chrono::milliseconds(30));  
    }
    cout << "Game Over!" << endl;
    return 0;
}