#pragma once

#include <ge211.hxx>

using Position = ge211::Posn<float>;
using Vector = ge211::Dims<float>;

struct ball {
    /// Data Members
    int radius;
    Position center;
    // Unit vector pointing in direction of ball movement (velocity unit vector)
    Vector heading;
    float speed;

    /// Member Functions
    ball(int rad, Vector heading, Position pos, float speed);

    // Returns true if the two circles are in contact (overlapped) with each other
    bool overlapped_with(ball target);

    // Finds the unit vector pointing to the target ball center (for collisions)
    Vector heading_to(ball target);

    // Finds the next instance of the ball
    ball next(double dt) const;
};

/// Helper Functions
// Finds the distance between ball 1 and ball 2
float distance(Position pos1, Position pos2);