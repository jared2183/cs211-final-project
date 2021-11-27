#include "model.hxx"
#include "config.hxx"

Model::Model()
    : p1(Car(car_radius, p1_start, {1, 0}, 0)),
      p2(Car(car_radius, p2_start, {-1, 0}, 180)),
      bullets(std::vector<ball>()),
      game_over(false)
{ }

void
Model::move_forward(Car& player, bool state) {
    player.control.thrust = state;
}

void
Model::turn_left(Car& player, bool state) {
    player.control.turning_left = state;
}

void
Model::turn_right(Car& player, bool state) {
    player.control.turning_right = state;
}

void collide(Car p1, Car p2) {
    Vector v1 = {p1.heading.width * p1.speed, p1.heading.height * p1.speed};
    Vector v2 = {p2.heading.width * p2.speed, p2.heading.height * p2.speed};
}

void
Model::shoot_bullet(Car& player) {
    if (!game_over) {
        player.shoot(bullets);
    }
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
}

bool
Model::is_game_over() {
    return game_over;
}