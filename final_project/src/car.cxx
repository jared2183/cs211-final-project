#include "car.hxx"
#include "ball.hxx"
#include "config.hxx"

// Helper Function
Vector normalize(Vector v) {
    float len = sqrt(v.width*v.width + v.height*v.height);
    return {v.width/len, v.height/len};
}

Car::Car(int rad, Position center, Vector heading, float theta)
    : ball(rad, heading, center, 0),
      theta(theta),
      velocity({0,0}),
      acceleration(0),
      hit_counter(0),
      control(Control {false, false, false})
{ }

void
Car::rotate(float degrees) {
    theta += degrees;
}

Vector
Car::forward_direction() const {
    float pi = acos(-1);
    return {sin(theta*pi/180), cos(theta*pi/180)};
}

void
Car::speed_up() {
    if (speed < top_speed) {
        acceleration = thrust_magnitude;
    } else {
        acceleration = 0;
    }
}

void
Car::slow_down() {
    if (speed > 0) {
        acceleration = drag;
    } else {
        acceleration = 0;
    }
}

void
Car::shoot(std::vector<ball>& bullets) {
    Vector bullet_heading = forward_direction();
    ball bullet = {bullet_radius, bullet_heading, center, bullet_speed};
    bullets.push_back(bullet);
}

void
Car::is_shot() {

}

Car
Car::next(double dt) const {
    Car nxt(*this);

    if (control.turning_left) {
        nxt.rotate(rotation_speed * dt);
    }
    if (control.turning_right) {
        nxt.rotate(-rotation_speed * dt);
    }
    if (control.thrust) {
        // Accelerates in forward direction (changes heading)
        nxt.speed_up();
        nxt.velocity.width += forward_direction().width * acceleration * dt;
        nxt.velocity.height += forward_direction().height * acceleration * dt;
    }
    else {
        // Decelerates in direction of movement (does not change heading)
        nxt.slow_down();
        nxt.velocity.width += heading.width * acceleration * dt;
        nxt.velocity.height += heading.height * acceleration * dt;
    }

    nxt.heading = normalize(nxt.velocity);
    nxt.center.x += velocity.width * dt;
    nxt.center.y += velocity.height * dt;

    return nxt;
}
