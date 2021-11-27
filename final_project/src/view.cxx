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
          winner1_sprite_("Player 1 wins!",winner_font_),
          winner2_sprite_("Player 2 wins!",winner_font_),
          winner3_sprite_("Draw!",winner_font_),
          player1_sprite_(car_radius, player1_color),
          player2_sprite_(car_radius, player2_color),
          player1_indicator_sprite_({indicator_width,indicator_height}, player1_color),
          player2_indicator_sprite_({indicator_width,indicator_height}, player2_color)
{ }

void
View::draw(ge211::Sprite_set& set) // should utilize model to call where the car is atm
{

    // If game is over, draw the end winner screen
    if (false) {
        // if winner is 1
        if (false) {
            set.add_sprite(winner1_sprite_, {0, 0}, 0);
        } else if (false) {
            set.add_sprite(winner2_sprite_, {0, 0}, 0);
        } else {
            set.add_sprite(winner3_sprite_,{0, 0}, 0);
        }
    } else { // If the game isn't over, let's continue the game!

        // Draw the water
        set.add_sprite(water_sprite_, {0,0}, 0);

        // Draw the platform
        int width_margin = window_dims_.width*(1/9);
        int height_margin = window_dims_.height*(1/9);
        set.add_sprite(platform_sprite_, {width_margin, height_margin}, 1);

        // Draw the cars (redone by every call to controller movement, update car),
        // replace with actual car

        // initial positions
        int car1_x = window_dims_.width*(8/9) - car_radius*2;
        int car2_y = window_dims_.height*(8/9) - car_radius*2;

        // add car positions based on new model's cars' positions
        set.add_sprite(player1_sprite_, {car1_x, height_margin}, 2);
        set.add_sprite(player2_sprite_, {width_margin, car2_y}, 2);

        // Draw the bullets (redone by every call to controller shots, update existing bullets)
        // if controller shoots bullet, add bullet to m_vector of bullets? for bullet in bullets,
        // add sprite

        // for bullet in bullet, add sprite for each bullet position
        set.add_sprite(bullet_sprite_, {0,0}, 3);

    }
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Bump";
}