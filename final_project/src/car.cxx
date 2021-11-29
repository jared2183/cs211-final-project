#include "car.hxx"
#include "ball.hxx"

// Helper Function
Vector normalize(Vector v) {
    float len = sqrt(v.width*v.width + v.height*v.height);
    return {v.width/len, v.height/len};
}

Car::Car(int rad, Position center, Vector heading, float theta, float
top_speed, float thrust, float drag, float rotation_speed)
        : ball(rad, heading, center, 0),
          theta(theta),
          velocity({0,0}),
          acceleration(0),
          hit_counter(0),
          control(Control {false, false, false}),
          top_speed(top_speed),
          thrust_magnitude(thrust),
          drag(drag),
          rotation_speed(rotation_speed)
{ }

void
Car::rotate(float degrees) {
    theta += degrees;
    if (theta >= 360) {
        theta -= 360;
    }
    else if (theta <= 0) {
        theta += 360;
    }
}

Vector
Car::forward_direction() const {
    float pi = acos(-1);
    printf("<%f,%f>\n", cosf(theta*pi/180), sinf(theta*pi/180));
    return {cosf(theta*pi/180), sinf(theta*pi/180)};
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
Car::shoot(std::vector<ball>& bullets, float bullet_radius, float
bullet_speed) {
    Vector bullet_heading = forward_direction();
    ball bullet = {bullet_radius, bullet_heading, center, bullet_speed};
    bullets.push_back(bullet);
}

void
Car::gets_shot() {

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
        nxt.acceleration = 0;
//        nxt.slow_down();
//        nxt.velocity.width += heading.width * acceleration * dt;
//        nxt.velocity.height += heading.height * acceleration * dt;
    }

    nxt.heading = normalize(nxt.velocity);
    nxt.center.x += velocity.width * dt;
    nxt.center.y += velocity.height * dt;

    return nxt;
}
