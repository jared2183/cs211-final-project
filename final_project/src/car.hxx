#include <ge211.hxx>
#include "ball.hxx"

#pragma once

struct Car : public ball {
    /// Data Members
    // The number of times the car has been hit by a bullet
    unsigned int hit_counter;
    // Direction the front of the car is currently facing
    float theta;
    Acceleration acceleration;

    /// Member Functions
    // Constructor
    ball(int rad, Velocity vel, Position pos);
    // Handles collisions with other player
    bool collide_with(Car player);
    // Rotates the car a certain number of degrees (intended to be
    // activated with the side arrow keys)
    void rotate(float degrees);
    // Will accelerate car forwards if thruster is on or decelerate if
    // thruster is off
    void accelerate(bool on_thrust);
    // Increments the hit counter
    void increment_hit();
    // Shoots a bullet from the front of the car
    void shoot(std::vector<ball>& bullets);
    // Calculates the next state of the car based on current velocity
    Car next(double dt) const;
};