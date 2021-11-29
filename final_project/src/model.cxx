#include "model.hxx"
//#include "car.hxx"
//#include "config.hxx"
#include "ball.hxx"

Model::Model(ge211::Dims<int> screen_dimensions)
        : p1(Car(car_radius, p1_start, {1, 0}, 0, top_speed,
                 thrust_magnitude, drag, rotation_speed)),
          p2(Car(car_radius, p2_start, {-1, 0}, 180, top_speed,
                 thrust_magnitude, drag, rotation_speed)),
          screen_dimensions_(screen_dimensions),
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
    p1.shoot(bullets, bullet_radius, bullet_speed);
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
    p2.shoot(bullets, bullet_radius, bullet_speed);
}

/// Handles object interactions

void collide(Car p1, Car p2) {
    Vector temp = p1.velocity;
    p1.velocity = p2.velocity;
    p2.velocity = temp;
}

void bullet_collisions() {
    return;
}

void
Model::on_frame(double dt) {
    // Car movement
    if (game_over) {
        return;
    }
    // if balls collide, run model collide
    if (((p1.center.x - p2.center.x)*(p1.center.x - p2.center.x) +
            (p1.center.y - p2.center.y)*(p1.center.y - p2.center.y))
            == (car_radius*2)*(car_radius*2)) {
        Vector temp = p1.velocity;
        p1.velocity = p2.velocity;
        p2.velocity = temp;
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