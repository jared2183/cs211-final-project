#pragma once

#include "model.hxx"

class View
{
public:
    // Type for window dimensions.
    using Dims = ge211::Dims<int>;

    // Constructs a view with reference to a model.
    // Optionally, you can specify the dimensions of the window.
    explicit View(
            Model const& model,
            Dims window_dims = {1280, 720});

    // Renders the state of the game (cars, water, platform) to the screen.
    void draw(ge211::Sprite_set& set);

    std::string initial_window_title() const;

private:
    ///
    /// PRIVATE MEMBER VARIABLES
    ///

    // The view can look at the model but doesn't change it.
    Model const& model_;

    // The dimensions of the window to open.
    Dims window_dims_;

    // The water.
    ge211::Rectangle_sprite const water_sprite_;

    // The platform.
    ge211::Rectangle_sprite const platform_sprite_;

    // The bullet.
    ge211::Rectangle_sprite const bullet_sprite_;

    // The fonts and text for the winner screen.
    ge211::Font winner_font_;
    ge211::Text_sprite winner1_sprite_;
    ge211::Text_sprite winner2_sprite_;
    ge211::Text_sprite winner3_sprite_;

    // The bump-er cars.
    ge211::Circle_sprite const player1_sprite_;
    ge211::Circle_sprite const player2_sprite_;

    // The bump-er cars' indicator.
    ge211::Rectangle_sprite const player1_indicator_sprite_;
    ge211::Rectangle_sprite const player2_indicator_sprite_;

};
