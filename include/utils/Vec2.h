#ifndef SUPERKK_VEC2_H
#define SUPERKK_VEC2_H

#include <cmath>

class Vec2 {
  private:
    double x;
    double y;

  public:
    Vec2() : x(0), y(0){};
    Vec2(double x, double y) : x(x), y(y){};

    double get_x() const {
        return x;
    }

    double get_y() const {
        return y;
    }

    void set_x(double n_x) {
        x = n_x;
    }

    void set_y(double n_y) {
        y = n_y;
    }

    int get_round_x() const {
        return static_cast<int>(round(x));
    }

    int get_round_y() const {
        return static_cast<int>(round(y));
    }

    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other) const {
        return {x - other.x, y - other.y};
    }

    Vec2 operator*(double scalar) const {
        return {x * scalar, y * scalar};
    }

    Vec2 operator+(double scalar) const {
        return {x + scalar, y + scalar};
    }

    Vec2 operator-(double scalar) const {
        return {x - scalar, y - scalar};
    }

    Vec2 operator/(double scalar) const {
        return {x / scalar, y / scalar};
    }
    
    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }
    
    bool operator!=(const Vec2& other) const {
        return !(*this == other);
    }
    
    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    
    Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    
    Vec2& operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    
    Vec2& operator/=(double scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    static Vec2 multiply(const Vec2& vec1, const Vec2& vec2) {
        return {vec1.x * vec2.x, vec1.y * vec2.y};
    }

    static Vec2 divide(const Vec2& vec1, const Vec2& vec2) {
        return {vec1.x / vec2.x, vec1.y / vec2.y};
    }
};
#endif  //SUPERKK_VEC2_H
