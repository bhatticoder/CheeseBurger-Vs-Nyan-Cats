#include "Powerup.h"
void Powerup::fall() {
    if (isActive) {
        // Move the power-up down
        this->setY(this->getY() + speed);
        // If it reaches the bottom of the screen, reset it
        if (this->getY() >= rows) {
            this->deactivate();
            this->reset();
        }
    }

}
void Powerup::deactivate() {
    isActive = false;
    std::cout << "PowerUp Deactivated!" << std::endl;
}
void Powerup::reset() {
    this->setY(0);  // Reset to the top of the screen
    isActive = false;
}
bool Powerup::collide(GameObject* other) {
    if (other == burger) {
        this->activate();
        return true;
    }
    return false;
}
void Powerup::draw() {
    cout << "p";
}
void ShieldPowerup::drawShield() {
    cout << "S";
}
void SpeedBoostPowerup::drawSpeedBoost() {
    cout << "B";
}