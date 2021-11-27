#pragma once

#include <ge211.hxx>
#include <car.hxx>
#include <ball.hxx>

using Rectangle = ge211::Rect<int>;

class Model
{
private:
    /// Data Members
    Rectangle platform;
    Car p1;
    Car p2;
    std::vector<ball> bullets;
    bool game_over;

    /// Member Functions
    bool on_platform(Car player);
    void collide(Car p1, Car p2);
    void on_frame(double dt);
    void handle_bullet_collisions();

public:
    Model();
    void move_forward(Car& player, bool state);
    void turn_left(Car& player, bool state);
    void turn_right(Car& player, bool state);
    void shoot_bullet(Car& player);
    bool is_game_over();
};