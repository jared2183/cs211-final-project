/// Game Configuration
ge211::geometry::Dims<int> scene_dims = {};

/// Bullet Configuration
int bullet_radius = 10; // in pixels
float bullet_speed = 75; // in pixels per second

/// Car Configuration
int car_radius = 50; // in pixels
float kb_multiplier;

float top_speed = 100; // in pixels per second
float thrust_magnitude = 80; // in pixels per second squared
float drag = 20; // in pixels per second squared
float rotation_speed = 50; // in degrees per second

Position p1_start = {0, 100};
Position p2_start = {100, 0};