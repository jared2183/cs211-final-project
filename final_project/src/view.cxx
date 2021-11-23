#include "view.hxx"

///
/// Defined constants
///

using Color = ge211::Color;
using Dims = ge211::Dims<int>;
using Sprite = ge211::Sprite;
using Sprite_set = ge211::Sprite_set;
using Transform = ge211::Transform;

// Radius of each car:
int const car_radius = 40;

// Effective space taken up by a car, including padding around it:
Dims const car_box {car_radius*2, car_radius*2};

// Thickness of bullet shot by car:
int const bullet_width = 1;
int const bullet_height = 3;

// Thickness of car's indicator:
int const indicator_width = 1;
int const indicator_height = 3;

// Size of font:
int const letter_font_size = car_radius;

// Background colors;
Color const
        bullet_color {0x33, 0x33, 0x33},
        water_color {0x66, 0x66, 0xCC},
        platform_color {0x00, 0x66, 0x00};

// Car colors;
Color const
        player1_color {0xFF, 0xFF, 0xFF},
        player2_color {0xFF, 0xFF, 0xFF};

///
/// Constructor
///

View::View(Model const& model, Dims window_dims)
        : model_(model),
          water_sprite_(window_dims, water_color),
          platform_sprite_({window_dims.width*(7/9),window_dims.height*(4/6)}, platform_color),
          bullet_sprite_({bullet_width,bullet_height}, bullet_color),
          winner_font_("sans.tff", letter_font_size),
          winner_sprite_("N/A",winner_font_),
          player1_sprite_(car_radius, player1_color),
          player2_sprite_(car_radius, player2_color),
          player1_indicator_sprite_({indicator_width,indicator_height}, player1_color),
          player2_indicator_sprite_({indicator_width,indicator_height}, player2_color)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
}
