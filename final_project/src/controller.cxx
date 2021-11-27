#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_key_down(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.turn_left(true);
    }
    if (key == ge211::Key::right()) {
        model_.turn_right(true);
    }
    if (key == ge211::Key::up()) {
        model_.move_forward(true);
    }
}

void
Controller::on_key_up(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.turn_left(false);
    }
    if (key == ge211::Key::right()) {
        model_.turn_right(false);
    }
    if (key == ge211::Key::up()) {
        model_.move_forard(false);
    }
    if (key.code() == ' ') {
        model_.fire_torpedo();
    }
    if (key.code() == 'q') {
        exit(0);
    }

}

