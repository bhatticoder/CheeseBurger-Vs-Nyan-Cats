#include<iostream>
using namespace std;
int main() {
    const int mapRows = 40;  // Define the number of rows for the map
    const int mapCols = 60;  // Define the number of columns for the map
    GameObject player(20, 30, mapRows, mapCols);  // Create the player at position (20, 30) on a 40x60 grid
    char direction;
    while (true) {
        system("cls");  // Clear the screen to redraw the map (for Windows)
        player.drawMap();  // Draw the map with the player's current position
        direction = _getch();  // Get user input
        if (direction == 'q' || direction == 'Q') {
            break;  // Exit the loop if the user presses 'q'
        }
        player.move(direction);  // Move player according to direction
    }
    cout << "Game Over!" << endl;
	return 0;
}