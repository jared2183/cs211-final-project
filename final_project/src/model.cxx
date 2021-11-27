#include "model.hxx"
#include "config.hxx"

Model::Model()
    : player1(Car(car_radius, p1_start, {1, 0})),
      player2(Car(car_radius, p2_start, {-1, 0})),
      bullets(std::vector<ball>)
{ }

void
Model::move_forward(Car player) {

}

void
Model::turn_left(Car player, double dt) {

}

void
Model::turn_right(Car player) {

}

void collide(Car player1, Car player2) {

}

void set_game_over() {

}