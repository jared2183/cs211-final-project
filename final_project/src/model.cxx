#include "model.hxx"
#include "config.hxx"

Model::Model()
    : p1(Car(car_radius, p1_start, {1, 0}, 0)),
      p2(Car(car_radius, p2_start, {-1, 0}, 180)),
      bullets(std::vector<ball>()),
      game_over(false)
{ }

/// Handles Controller Input
void
Model::p1_move_forward(bool state) {
    p1.control.thrust = state;
}

void
Model::p1_turn_left(bool state) {
    p1.control.turning_left = state;
}

void
Model::p1_turn_right(bool state) {
    p1.control.turning_right = state;
}

void
Model::p1_shoot_bullet() {
    p1.shoot(bullets);
}

void
Model::p2_move_forward(bool state) {
    p2.control.thrust = state;
}

void
Model::p2_turn_left(bool state) {
    p2.control.turning_left = state;
}

void
Model::p2_turn_right(bool state) {
    p2.control.turning_right = state;
}

void
Model::p2_shoot_bullet() {
    p2.shoot(bullets);
}

/// Handles object interactions

void collide(Car p1, Car p2) {
    Vector v1 = p1.velocity;
    Vector v2 = p2.velocity;
}

void bullet_collisions() {

}

void
Model::on_frame(double dt) {
    // Car movement
    if (game_over) {
        return;
    }
    p1 = p1.next(dt);
    p2 = p2.next(dt);

    // Bullet movement
    for (ball& bullet: bullets) {
        bullet = bullet.next(dt);
    }
}

bool
Model::is_game_over() {
    return game_over;
}