#include <ge211.hxx>

using Position = ge211::Posn<float>;
using Velocity = ge211::Dims<float>;
using Acceleration = ge211::Dims<float>;

struct ball
{
    /// Data Members
    int radius;
    // Movement Data and Heading
    Position center;
    Velocity heading;
    float speed;

    /// Member Functions
    // Calculates the distance between the centers of two circles
    float distance_to(ball target);
    // Returns true if the two circles are in contact (overlapped) with each
    // other
    bool overlapped_with(ball target);
    // Finds the angle between two circles (meant to handle collisions)
    float angle_to(ball target);
};