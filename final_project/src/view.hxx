#pragma once

#include <ge211.hxx>

// Forward declaration of our model struct. This lets us use references
// to Model in this file even though the definition isn’t visible. (Just
// like in C.)
struct Model;

class View
{
public:
    //
    // CONSTRUCTOR
    //
    explicit View(Model const&);

    //
    // MEMBER FUNCTIONS
    //
    void draw(ge211::Sprite_set&);

private:
    //
    // MEMBER VARIABLES
    //
    Model const& model;

    // The water.
    ge211::Rectangle_sprite const water_sprite_;
    // The platform.
    ge211::Rectangle_sprite const platform_sprite_;
    // The bump-er cars.
    ge211::Circle_sprite const player1_sprite_;
    ge211::Circle_sprite const player2_sprite_;
    // The fonts and text for the winner screen.
    ge211::Font winner_font_;
    ge211::Text_sprite winner1_sprite_;
    ge211::Text_sprite winner2_sprite_;
    ge211::Text_sprite winner3_sprite_;
    // The bump-er cars' indicator.
    ge211::Rectangle_sprite const indicator_sprite_;
};