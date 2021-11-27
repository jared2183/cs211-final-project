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
    void bullet_collisions();

public:
    Model();
    void p1_move_forward(bool state);
    void p1_turn_left(bool state);
    void p1_turn_right(bool state);
    void p1_shoot_bullet();
    void p2_move_forward(bool state);
    void p2_turn_left(bool state);
    void p2_turn_right(bool state);
    void p2_shoot_bullet();
    bool is_game_over();
};