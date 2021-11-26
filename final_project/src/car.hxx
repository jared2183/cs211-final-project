#include <ge211.hxx>
#include <circle.hxx>

#pragma once

struct Car : public circle {
    /// Data Members
    // The number of times the car has been hit by a bullet
    unsigned int hit_counter;

    /// Member Functions
    // Handles collisions with other player
    bool collide_with(Car player);
    // Rotates the car a certain number of degrees (intended to be
    // activated with the side arrow keys)
    void rotate(float degrees);
    // Will accelerate car forwards if thruster is on or decelerate if
    // thruster is off
    void accelerate(bool on_thrust);
    // Calculates the next state of the car based on current velocity
    Car next(double dt) const;
    // Increments the hit counter
    void on_hit();
};