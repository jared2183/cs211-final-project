#include "car.hxx"

Car::Car(int rad, Position center) {
    : radius(rad),
      center(center)
      hit_counter(0);
}
