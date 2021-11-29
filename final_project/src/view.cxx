// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "view.hxx"
#include "model.hxx"
#include "config.hxx"

///
/// VIEW CONSTANTS
///

// Platform position
ge211::Dims<int> platform {128, 72};
ge211::Dims<int> platform_pos {8*scene_dims.width/10, 8*scene_dims.height/10};

///
/// VIEW CONSTRUCTOR
///

// Data members that are references cannot be initialized by assignment
// in the constructor body and must be initialized in a member
// initializer list.
View::View(Model const& m)
        : model(m),
          water_sprite_(scene_dims, water_color),
          platform_sprite_(platform_pos.into<int>(), platform_color),
          player1_sprite_(car_radius, player1_color),
          player2_sprite_(car_radius, player2_color),
          bullet_sprite_(bullet_radius, "000000"),
          winner_font_("sans.ttf", letter_font_size),
          winner1_sprite_("Player 1 wins!",winner_font_),
          winner2_sprite_("Player 2 wins!",winner_font_),
          winner3_sprite_("Draw!",winner_font_),
          indicator_sprite_({indicator_width,indicator_height}, indicator_color),
          arrow_sprite_("arrow.png")
{ }


///
/// VIEW FUNCTIONS
///

// Use `Sprite_set::add_sprite(Sprite&, Position)` to add each sprite
// to `sprites`.
void
View::draw(ge211::Sprite_set& sprites) {
    int p1_x = model.p1.center.x;
    int p1_y = model.p1.center.y;
    int p2_x = model.p2.center.x;
    int p2_y = model.p2.center.y;

    // WINNER SCREEN
    if (p1_x > platform.width + platform_pos.width ||
        p1_y > platform.height + platform_pos.height
        || p1_x + 2*car_radius < platform.width ||
        p1_y + 2*car_radius < platform.height) {
        sprites.add_sprite(winner2_sprite_, {0, 0}, 0);
    } else if (p2_x > platform.width + platform_pos.width ||
               p2_y > platform.height + platform_pos.height
               || p2_x + 2*car_radius < platform.width ||
               p2_y + 2*car_radius < platform.height) {
        sprites.add_sprite(winner1_sprite_, {0, 0}, 0);

    } else { // If the game isn't over, let's continue the game!

        // Add water
        sprites.add_sprite(water_sprite_, {0, 0}, 0);
        // Add platform
        sprites.add_sprite(platform_sprite_, {128, 72}, 2);
        // Add bumper car objects
        sprites.add_sprite(player1_sprite_, {p1_x, p1_y}, 4);
        sprites.add_sprite(arrow_sprite_, {p1_x+car_radius-24, p1_y+18}, 5,
                           ge211::geometry::Transform{}.set_scale(0.06035).set_rotation(model.p1.theta));
        sprites.add_sprite(player2_sprite_, {p2_x, p2_y}, 4);
        sprites.add_sprite(arrow_sprite_, {p2_x+car_radius-24, p2_y+18}, 5,
                           ge211::geometry::Transform{}.set_scale(0.06035).set_rotation(model.p2.theta));
    }
}