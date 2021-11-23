#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller(int width, int height);

protected:
    // Called each time a key is pressed. We'll forward this to model.
    void on_key(ge211::Key key) override;

    // Called each time a key is released. We'll forward this to model.
    void on_key_up(ge211::Key key) override;

    // Updates each frame based on elapsed time in seconds.
    // We'll forward this to model.
    void on_frame(double dt) override;

    // Called by ge211 when the game needs to redraw the screen.
    // We'll delegate this to view.
    void draw(ge211::Sprite_set& set) override;

private:
    Model model_;
    View view_;
};
