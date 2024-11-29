//#include "Game.h"
//#include "Cheeseburger.h"
//
//enum powerup_type { Shield, score_multiplier, speed_boost };
//
//class Powerup : public game_object {
//private:
//    powerup_type type;
//    int duration;
//    bool isactive;
//    Cheeseburger* burger;
//    static const int maxPowerUps = 3;
//    int row;
//    int col;
//    int rows;  // Grid rows
//    int cols;  // Grid columns
//public:
//    Powerup(int x, int y, powerup_type type, int duration, Cheeseburger* burger, int rows, int cols);
//    void activate();
//    void deactivate();
//    void reset();
//    bool isActive() const { return isactive; }
//    powerup_type getType() const { return type; }
//    int getDuration() const { return duration; }
//    bool collide(game_object* other) override;
//    // Generalized draw function for all power-ups
//    void draw()override;
//    void move(char mov)override;
//    void fall();
//};