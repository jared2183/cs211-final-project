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
    Car player1;
    Car player2;
    std::vector<ball> bullets;

    /// Member Functions
    bool on_platform(Car player);
    void collide(Car player1, Car player2);
    void set_game_over();
    void on_frame();

public:
    Model();
    void move_forward(Car player);
    void turn_left(Car player);
    void turn_right(Car player);
    bool is_game_over();
};