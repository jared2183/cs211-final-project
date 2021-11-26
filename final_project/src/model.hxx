#pragma once

#include <ge211.hxx>
#include <car.hxx>
#include <circle.hxx>

using Rectangle = ge211::Rect<int>;

class Model
{
private:
    Rectangle platform;
    Car player1;
    Car player2;
    std::vector<circle> bullets;

public:
    void move_forward(Car player);
    void turn_left(Car player);
    void turn_right(Car player);
    void collide(Car player1, Car player2);
    void set_game_over();
    void on_frame();
};