#include "ball.hxx"
#include "config.hxx"
#include <cmath>

ball::ball(int rad, Vector heading, Position center, float speed)
    : radius(rad),
      center(center),
      heading(heading),
      speed(speed)
{ }

bool
ball::overlapped_with(ball target) {
    int sum_rad = radius + target.radius;
    return distance(center, target.center) <= float(sum_rad);
}

Vector
ball::heading_to(ball target) {
    float len = distance(center, target.center);
    float ux = (target.center.x - center.x)/len;
    float uy = (target.center.y - center.y)/len;
    // Returns normalized unit vector
    return {ux, uy};
}

ball
ball::next(double dt) const {
    ball next_ball(*this);
    next_ball.center.x += heading.width * speed * dt;
    next_ball.center.y += heading.height * speed * dt;
    return next_ball;
}

static float
distance(Position pos1, Position pos2) {
    float dx = pos1.x - pos2.x;
    float dy = pos1.y - pos2.y;
    return sqrt(dx * dx + dy * dy);
}