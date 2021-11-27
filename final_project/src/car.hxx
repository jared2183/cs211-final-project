#include <ge211.hxx>
#include "ball.hxx"

struct Car : public ball {
    /// Data Members
    // Direction the front of the car is currently facing (follows unit circle conventions)
    float theta;
    Vector velocity;
    float acceleration;
    // The number of times the car has been hit by a bullet
    unsigned int hit_counter;

    /// Member Functions
    Car(int rad, Position center, Vector heading);
    // Handles collisions with other player
    bool collide_with(Car player);
    // Rotates the car a certain number of degrees (intended to be
    // activated with the side arrow keys)
    void rotate(float degrees);
    // Will accelerate car forwards to maximum speed
    void speed_up(double dt);
    // Will decelerate the car until its speed is 0
    void slow_down(double dt);
    // Increments the hit counter
    void increment_hit();
    // Shoots a bullet from the front of the car
    void shoot(std::vector<ball>& bullets);
    // Calculates the next state of the car based on current velocity
    Car next(double dt) const;
};