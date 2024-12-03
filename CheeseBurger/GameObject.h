#pragma once
#include <iostream>
#include <string>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
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
    int getRow()const { return rows; }
    int getCol()const { return cols; }
    int getWidth() const { return width; }
    int getHeight() const { return heigth; }
    void printColored(const std::string& text, const std::string& color) {
        std::cout << color << text << RESET;
    }
};