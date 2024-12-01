#include "Powerup.h"
Powerup::Powerup(int x, int y, int rows, int cols, Cheeseburger* burger, int speed = 1)
    : GameObject(x, y, 4, 2), burger(burger), rows(rows), cols(cols), isActive(false), speed(speed), duration(10) {}
void Powerup::draw() {
    cout << "p";
}
