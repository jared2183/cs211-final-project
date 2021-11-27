// YOU DEFINITELY NEED TO MODIFY THIS FILE.

#include "view.hxx"
#include "model.hxx"

///
/// VIEW CONSTANTS
///

// Colors are red-green-blue(-alpha), each component
// from 0 to 255.
static ge211::Color const water_color {212, 241, 249};
static ge211::Color const platform_color {128, 128, 128};
static ge211::Color const player_color {255, 255, 255};

// Platform position
Position platform {128, 72};
// Radius of each car:
int const car_radius = 15;
// Starting margin of each car:
int const car_margin = 10;


///
/// VIEW CONSTRUCTOR
///

// Data members that are references cannot be initialized by assignment
// in the constructor body and must be initialized in a member
// initializer list.
View::View(Model const& m)
        : model(m),
          water_sprite_(m.config.scene_dims, water_color),
          platform_sprite_(8*m.config.scene_dims/10, platform_color),
          player1_sprite_(car_radius, player_color)
{ }


///
/// VIEW FUNCTIONS
///

// Use `Sprite_set::add_sprite(Sprite&, Position)` to add each sprite
// to `sprites`.
void
View::draw(ge211::Sprite_set& sprites)
{
//    // 'ball_sprite' placed at ball's bounding box's top-left
//    sprites.add_sprite(ball_sprite, model.ball.top_left().into<int>(), 1);
//    // 'paddle_sprite' placed where model says paddle is
//    sprites.add_sprite(paddle_sprite, model.paddle.top_left(), 1);

//    // 'brick_sprite' placed for each brick in 'model.bricks'
//    for (Block brick : model.bricks) {
//        sprites.add_sprite(brick_sprite, {brick.x, brick.y}, 1);
//    }

    // Add water
    sprites.add_sprite(water_sprite_, {0,0}, 0);
    // Add platform
    sprites.add_sprite(platform_sprite_, platform.into<int>(), 2);
    // Add bumper car objects
    /// should change to actual car's position based on model
    Position car_pos1 = {platform.x+car_margin,platform.y+car_margin};
    Position car_pos2 = {platform.x+1024-car_margin-car_radius*2,
                         platform.y+576-car_margin-car_radius*2};
    sprites.add_sprite(player1_sprite_, car_pos1.into<int>(), 3);
    sprites.add_sprite(player1_sprite_, car_pos2.into<int>(), 3);

}

ge211::Dims<int>
View::initial_window_dimensions() const
{
    return model.config.scene_dims;
}

