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
Car::speed_up() {

}

void
Car::slow_down() {

}