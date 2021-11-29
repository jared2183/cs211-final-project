#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller(ge211::Dims<int> board_dimensions);
    ge211::Dims<int> initial_window_dimensions() const override;

protected:
    void draw(ge211::Sprite_set& set) override;
    // Called by ge211 when the game engine is ready. We use this to tell
    // the model to react to time passing.
    void on_frame(double dt) override;
    void on_key_down(ge211::Key) override;
    void on_key_up(ge211::Key) override;

private:
    Model model_;
    View view_;
    ge211::Dims<int> screen_dimensions_;
};
