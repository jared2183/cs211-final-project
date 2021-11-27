#include "controller.hxx"

Controller::Controller(ge211::Dims<int> screen_dimensions)
        : model_(screen_dimensions),
          view_(model_),
          screen_dimensions_(screen_dimensions)
{ }

///
/// Public member functions
///

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return screen_dimensions_;
}


void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}


void
Controller::on_key(ge211::Key key)
{
    // PLAYER 1 MOVEMENTS
    // if W, accelerate P1 forward
    if (key.code() == 'q') {

    }
    // if A, rotate P1 left
    if (key.code() == 'a') {

    }
    // if S, accelerate P1 backwards
    if (key.code() == 's') {

    }
    // if D, rotate P1 right
    if (key.code() == 'd') {

    }

    // PLAYER 2 MOVEMENTS
    // if up arrow, accelerate P2 forward
    if (key == ge211::Key::up()) {

    }
    // if left arrow, rotate P2 left
    if (key == ge211::Key::left()) {

    }
    // if down arrow, accelerate P2 backwards
    if (key == ge211::Key::down()) {

    }
    // if right arrow, rotate P2 right
    if (key == ge211::Key::right()) {

    }
}

void
Controller::on_key_up(ge211::Key key)
{
    // quit the game
    if (key.code() == 'q') {
        exit(0);
    }

    // PLAYER 1 MOVEMENT

    // PLAYER 2 MOVEMENT

    // PLAYER 1 GUN
    // if Q, P1 shoots bullet in facing direction
    if (key.code() == 'q') {

    }

    // PLAYER 2 GUN
    // if (Right) Shift, P2 shoots bullet in facing direction
    if (key == ge211::Key::shift()) {

    }
}

void
Controller::on_frame(double dt)
{
    // for each frame, update each player's position based on
    // called collisions, number of hits on each, and whether bullet
    // has hit a car successfully enough to launch them out of the platform
}