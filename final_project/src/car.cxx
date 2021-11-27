#include "car.hxx"
#include "ball.hxx"
#include "config.hxx"

Car::Car(int rad, Position center, Vector heading)
    : ball(rad, heading, center, 0),
      hit_counter(0)
{ }

void
Car::rotate(float degrees) {
    theta += degrees;
    heading = {sin(theta), cos(theta)};
}

void
Car::speed_up(double dt) {
    if (speed < top_speed) {
        speed += thrust*dt;
    }
    else {
        speed = top_speed;
    }
    center.x += heading.width*speed*dt;
    center.y += heading.height*speed*dt;
}

void
Car::slow_down(double dt) {
    if (speed > 0) {
        speed -= drag*dt;
    }
    else {
        speed = 0;
    }
    center.x += heading.width*speed*dt;
    center.y += heading.height*speed*dt;
}

void
Car::shoot(std::vector<ball>& bullets) {
    Position bullet_pos = Position(center.x)
    ball bullet = {bullet_radius, heading, }
}