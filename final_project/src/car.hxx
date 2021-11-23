#include <ge211.hxx>

#pragma once

using Position = ge211::Posn<float>;
using Velocity = ge211::Dims<float>;
using Acceleration = ge211::Dims<float>;

struct Car {
    /// Data Members
    int radius;
    // Car Movement Data and Heading
    Position center;
    Velocity velocity;
    Acceleration acceleration;
    float theta;

    // The number of times the car has been hit by a bullet
    unsigned int hit_counter;

    /// Member Functions
    bool hits_car(Car player);
    Car next(double dt) const;

};