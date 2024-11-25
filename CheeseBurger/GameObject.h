#pragma once
#include <iostream>
#include <string>
using namespace std;
struct color {
    int r, g, b;
};
class GameObject {
protected:
    int x, y;            // Position of the object (not currently used but can be extended)
    //color colors;        // Color of the object (not currently used but can be extended)
    int row, col;        // Position on the map grid
    int rows, cols;      // Dimensions of the map grid
public:
    // Constructor
    //GameObject() {}
    GameObject(int startRow, int startCol, int rows, int cols);
    // Virtual functions
    virtual void move(char direction) = 0;
    virtual void draw() = 0; 
    // virtual void collide(GameObject* other) = 0; 
};

//// Derived class
//class Cheeseburger : public GameObject {
//private:
//    int speed;
//    int lives;
//    int score;
//public:
//    // Constructor
//    Cheeseburger(int startX, int startY, int w, int h, color col, int initialSpeed, int initialLives)
//        : speed(initialSpeed), lives(initialLives), score(0) {
//        x = startX;
//        y = startY;
//        width = w;
//        height = h;
//        colors = col;
//    }
//
//    // Override draw method
//    void draw() override {
//        std::cout << "Drawing Cheeseburger at (" << x << ", " << y << ") with color ("
//            << colors.r << ", " << colors.g << ", " << colors.b << ").\n";
//    }
//
//    // Override move method
//    void move(const std::string& direction) override {
//        if (direction == "left") {
//            x -= speed;
//            std::cout << "Cheeseburger moved left to (" << x << ", " << y << ").\n";
//        }
//        else if (direction == "right") {
//            x += speed;
//            std::cout << "Cheeseburger moved right to (" << x << ", " << y << ").\n";
//        }
//        else {
//            std::cout << "Invalid direction for Cheeseburger movement.\n";
//        }
//    }
//
//    // Override collide method
//    void collide(GameObject* other) override {
//        // Determine type of the collided object using dynamic_cast
//        if (auto* nyanCat = dynamic_cast<NyanCat*>(other)) {
//            lives -= 1;
//            std::cout << "Collided with Nyan Cat! Lives left: " << lives << "\n";
//        }
//        else if (auto* powerUp = dynamic_cast<PowerUp*>(other)) {
//            score += 10;
//            std::cout << "Collided with PowerUp! Score: " << score << "\n";
//        }
//        else if (auto* friendObj = dynamic_cast<Friend*>(other)) {
//            lives += 1;
//            std::cout << "Collided with Friend! Lives increased to: " << lives << "\n";
//        }
//        else {
//            std::cout << "Collided with an unknown object.\n";
//        }
//    }
//};
//
//// Example objects for collision
//class NyanCat : public GameObject {
//public:
//    void draw() override {
//        std::cout << "Drawing Nyan Cat.\n";
//    }
//    void move(const std::string& direction) override {
//        std::cout << "Nyan Cat moved " << direction << ".\n";
//    }
//    void collide(GameObject* other) override {
//        std::cout << "Nyan Cat collided with something.\n";
//    }
//};
//
//class PowerUp : public GameObject {
//public:
//    void draw() override {
//        std::cout << "Drawing PowerUp.\n";
//    }
//    void move(const std::string& direction) override {
//        std::cout << "PowerUp moved " << direction << ".\n";
//    }
//    void collide(GameObject* other) override {
//        std::cout << "PowerUp collided with something.\n";
//    }
//};
//
//class Friend : public GameObject {
//public:
//    void draw() override {
//        std::cout << "Drawing Friend.\n";
//    }
//    void move(const std::string& direction) override {
//        std::cout << "Friend moved " << direction << ".\n";
//    }
//    void collide(GameObject* other) override {
//        std::cout << "Friend collided with something.\n";
//    }
//};