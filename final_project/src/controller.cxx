#include "controller.hxx"

Controller::Controller(ge211::Dims<int> screen_dimensions)
        : model_(scene_dims),
          view_(model_),
          screen_dimensions_(screen_dimensions)
{ }

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return screen_dimensions_;
}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}


void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_key_down(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.p2_turn_right(true);
        if (model_.p2.control.turning_left) {
            printf("P2 rotated left!\npos1{%f,%f; %f}, pos2{%f,%f; %f}\n", model_.p1.center.x, model_.p1.center.y,
                   model_.p1.theta,
                   model_.p2.center.x,model_.p2.center.y, model_.p2.theta);
        }
    }
    if (key == ge211::Key::right()) {
        model_.p2_turn_left(true);
        printf("P2 rotated right!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key == ge211::Key::up()) {
        model_.p2_move_forward(true);
        printf("P2 thrust!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key == ge211::Key::shift()) {
        model_.p2_shoot_bullet();
        printf("P2 shot bullet!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key.code() == 'a') {
        model_.p1_turn_right(true);
        printf("P1 rotated left!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key.code() == 'd') {
        model_.p1_turn_left(true);
        printf("P1 rotated right!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key.code() == 'w') {
        model_.p1_move_forward(true);
        printf("P1 thrust!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key.code() == ' ') {
        model_.p1_shoot_bullet();
        printf("P1 shot bullet!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key.code() == 'q') {
        exit(0);
    }
}

void
Controller::on_key_up(ge211::Key key) {
    if (key == ge211::Key::left()) {
    //        model_.p2.theta -= 1;
       model_.p2_turn_right(false);
       if (model_.p2.control.turning_left) {
           printf("P2 stopped left!\npos1{%f,%f; %f}, pos2{%f,%f; %f}\n", model_.p1.center.x, model_.p1.center.y,
                  model_.p1.theta, model_.p2.center.x,model_.p2.center.y, model_.p2.theta);
        }
    }
    if (key == ge211::Key::right()) {
        model_.p2_turn_left(false);
        printf("P2 stopped right!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
        model_.p2.center.x,model_.p2.center.y);
    }
    if (key == ge211::Key::up()) {
        model_.p2_move_forward(false);
    }

    if (key.code() == 'a') {
        model_.p1_turn_right(false);
        if (model_.p2.control.turning_left) {
            printf("P1 stopped left!\npos1{%f,%f; %f}, pos2{%f,%f; %f}\n", model_.p1.center.x, model_.p1.center.y,
                   model_.p1.theta, model_.p2.center.x,model_.p2.center.y, model_.p2.theta);
        }
    }
    if (key.code() == 'd') {
        model_.p1_turn_left(false);
        printf("P1 stopped right!\npos1{%f,%f}, pos2{%f,%f}\n", model_.p1.center.x, model_.p1.center.y,
               model_.p2.center.x,model_.p2.center.y);
    }
    if (key.code() == 'w') {
        model_.p1_move_forward(false);
    }
};