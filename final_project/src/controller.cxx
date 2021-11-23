#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

///
/// Public member functions
///

void
Controller::on_key(ge211::Key key)
{
    // PLAYER 1 MOVEMENTS
    // if W, move P1 forward
    // if A, tilt P1 left
    // if S, move P1 backwards
    // if D, tilt P1 right

    // PLAYER 2 MOVEMENTS
    // if up arrow, move P2 forward
    // if left arrow, tilt P2 left
    // if down arrow, move P2 backwards
    // if right arrow, tilt P2 right
}

void
Controller::on_key_up(ge211::Key key)
{
    // PLAYER 1 GUN
    // if Q, P1 shoots bullet in facing direction

    // PLAYER 2 GUN
    // if Right Shift, P2 shoots bullet in facing direction
}

void
Controller::on_frame(double dt)
{
    // for each frame, update each player's position based on
    // called collisions, number of hits on each, and whether bullet
    // has hit a car successfully enough to launch them out of the platform
}

void
Controller::draw(ge211::Sprite_set& sprites)
{
    // draw the sprites!
    view_.draw(sprites);
}