#include "GameObject.h"
#include <iostream>
GameObject::GameObject(int startRow, int startCol, int rows, int cols)
    : x(startRow), y(startCol), width(4), heigth(2), rows(rows), cols(cols) {
}