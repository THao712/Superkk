#ifndef SUPERKK_CIRCLENODE_H
#define SUPERKK_CIRCLENODE_H

#include <graphics.h>
#include <conio.h>
#include "RenderableNode.h"

class CircleRender : public Renderer {
public:
    Vec2 a1;
    Vec2 a2;
    Vec2 b1;
    Vec2 b2;

    CircleRender() : a1(), a2(), b1(), b2() {}

    void apply_transform(const Transform& transform) override {
        a1 = transform.apply_to(a1);
        a2 = transform.apply_to(a2);
        b1 = transform.apply_to(b1);
        b2 = transform.apply_to(b2);
    }

    void render() override {
        double k = 4.0 / 3 * (1 - sqrt(2) / 2);
        Vec2 c1(a1.get_x() * (1 - k), k * b2.get_y());
        Vec2 c2(k * a1.get_x(), b2.get_y() * (1 - k));
        POINT points[4] = {
                {a1.get_round_x(), a1.get_round_y()},
                {b2.get_round_x(), b2.get_round_y()},
                {a2.get_round_x(), a2.get_round_y()},
                {b1.get_round_x(), b1.get_round_y()},
        };
        setlinecolor(GREEN);
        polyline(points, 4);
    };
};

class CircleNode : public RenderableNode {
private:
    CircleRender *renderer;
    double radius;
public:
    CircleNode() : radius(10) {
        renderer = new CircleRender();
    }
    explicit CircleNode(double radius) : radius(radius) {
        renderer = new CircleRender();
    }
    Renderer* get_renderer() override {
        renderer->a1 = Vec2(-radius, 0);
        renderer->a2 = Vec2(radius, 0);
        renderer->b1 = Vec2(0, -radius);
        renderer->b2 = Vec2(0, radius);
        renderer->apply_transform(update_world_transform());
        return renderer;
    }
};


#endif //SUPERKK_CIRCLENODE_H
