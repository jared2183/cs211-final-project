#pragma once

/// Game Configuration
const ge211::Dims<int> scene_dims = {1280,720}; // in pixels

/// Bullet Configuration
const int bullet_radius = 10; // in pixels
const float bullet_speed = 75; // in pixels per second

/// Car Configuration
const int car_radius = 35; // in pixels
const int car_margin = 10; // in pixels
const float kb_multiplier = 1;

const float top_speed = 75; // in pixels per second
const float thrust_magnitude = 300; // in pixels per second squared
const float drag = -20; // in pixels per second squared
const float rotation_speed = 200; // in degrees per second

const Position p1_start = {128+car_margin, 72+car_margin};
const Position p2_start = {1152-2*car_radius-car_margin, 648-2*car_radius-car_margin};

// Car colors;
ge211::Color const
        player1_color {78, 42, 132},
        player2_color {134, 38, 51};

// Thickness of car's indicator:
int const indicator_width = car_radius + 55;
int const indicator_height = 2;

// Size of font:
int const letter_font_size = car_radius;

// Colors are red-green-blue(-alpha), each component
// from 0 to 255.
static ge211::Color const water_color {212, 241, 249};
static ge211::Color const platform_color {128, 128, 128};
static ge211::Color const indicator_color {0, 0, 0};
