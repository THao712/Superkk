#ifndef SUPERKK_RECT_H
#define SUPERKK_RECT_H

#include "Vec2.h"

class Rect {
  private:
    double x;
    double y;
    double width;
    double height;

  public:
    Rect(double x, double y, double width, double height) : x(x), y(y), width(width), height(height){};

    Vec2 getCenter() const {
        return {x + width / 2, y + height / 2};
    }
};

#endif  //SUPERKK_RECT_H
