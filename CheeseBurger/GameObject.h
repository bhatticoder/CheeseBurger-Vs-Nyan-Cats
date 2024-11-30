#pragma once
#include <iostream>
#include <string>
using namespace std;
class GameObject {
protected:
    int x, y;            // Position of the object (not currently used but can be extended)
    //color colors;        // Color of the object (not currently used but can be extended)
    int width, heigth;        // Position on the map grid
    int rows, cols;      // Dimensions of the map grid
public:
    // Constructor
    GameObject(int startRow, int startCol, int rows, int cols);
    virtual void move(char direction) = 0;
    virtual void draw() = 0;
    virtual bool collide(GameObject* other) = 0;
    // Add getter methods
    void setY(int y) { y = y; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return heigth; }
};
