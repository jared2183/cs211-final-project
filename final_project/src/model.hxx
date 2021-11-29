#pragma once

#include <ge211.hxx>
#include "car.hxx"
#include "config.hxx"

using Platform = ge211::Rect<int>;

class Model
{
public:
    Car p1;
    Car p2;
    Model(ge211::Dims<int> screen_dimensions);
    void p1_move_forward(bool state);
    void p1_turn_left(bool state);
    void p1_turn_right(bool state);
    void p1_shoot_bullet();

    void p2_move_forward(bool state);
    void p2_turn_left(bool state);
    void p2_turn_right(bool state);
    void p2_shoot_bullet();
    bool is_game_over();

    void on_frame(double dt);
private:
    /// Data Members
    ge211::Dims<int> screen_dimensions_;
    Platform platform;
    std::vector<ball> bullets;
    bool game_over;

    /// Member Functions
    bool on_platform(Car player);
    void collide(Car p1, Car p2);
    void bullet_collisions();
};