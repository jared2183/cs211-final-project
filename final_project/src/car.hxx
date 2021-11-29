#pragma once

#include <ge211.hxx>
#include "ball.hxx"

struct Control {
    bool turning_left = false;
    bool turning_right = false;
    bool thrust = false;
};

struct Car : public ball {
    /// Data Members
    // Direction the front of the car is currently facing (NOT same as heading)
    // in DEGREES (0 is facing right, 180 is facing left, goes from 0 to 359)
    float theta;
    Vector velocity;
    float acceleration;
    // The number of times the car has been hit by a bullet
    unsigned int hit_counter;
    Control control;
    float top_speed;
    float thrust_magnitude;
    float drag;
    float rotation_speed;

    /// Member Functions
    Car(int rad, Position center, Vector heading, float theta, float
    top_speed, float thrust, float drag, float rotation_speed);
    // Rotates the car a certain number of degrees (intended to be
    // activated with the side arrow keys)
    void rotate(float degrees);
    // Finds the direction the car is pointing in (NOT equal to heading, or direction of movement)
    // Based completely off of theta and NOT velocity
    Vector forward_direction() const;
    // Will accelerate car forwards to maximum speed
    void speed_up();
    // Will decelerate the car until its speed is 0
    void slow_down();
    // Increments the hit counter and applies knockback
    void gets_shot();
    // Shoots a bullet from the front of the car
    void shoot(std::vector<ball>& bullets, float bullet_radius, float
    bullet_speed);
    // Calculates the next state of the car based on current velocity
    Car next(double dt) const;
};