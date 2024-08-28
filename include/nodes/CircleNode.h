#ifndef SUPERKK_CIRCLENODE_H
#define SUPERKK_CIRCLENODE_H

#include <graphics.h>
#include <conio.h>
#include "RenderableNode.h"

class CircleRender : public Renderer {
public:
    Vec2 a1;
    Vec2 a2;
    Vec2 a3;
    Vec2 a4;

    CircleRender() : a1(), a2(), a3(), a4() {}

    void apply_transform(const Transform& transform) override {
        a1 = transform.apply_to(a1);
        a2 = transform.apply_to(a2);
        a3 = transform.apply_to(a3);
        a4 = transform.apply_to(a4);
    }

    void render() override {
        Vec2 m1 = (a1 + a2) / 2;
        Vec2 m2 = (a2 + a3) / 2;
        Vec2 m3 = (a3 + a4) / 2;
        Vec2 m4 = (a4 + a1) / 2;
        double k = 0.551784;
        Vec2 c1 = a2 * k + m1 * (1 - k);
        Vec2 c2 = a2 * k + m2 * (1 - k);
        Vec2 c3 = a3 * k + m2 * (1 - k);
        Vec2 c4 = a3 * k + m3 * (1 - k);
        Vec2 c5 = a4 * k + m3 * (1 - k);
        Vec2 c6 = a4 * k + m4 * (1 - k);
        Vec2 c7 = a1 * k + m4 * (1 - k);
        Vec2 c8 = a1 * k + m1 * (1 - k);
        POINT points[13] = {
            {m1.get_round_x(), m1.get_round_y()},
            {c1.get_round_x(), c1.get_round_y()},
            {c2.get_round_x(), c2.get_round_y()},
            {m2.get_round_x(), m2.get_round_y()},
            {c3.get_round_x(), c3.get_round_y()},
            {c4.get_round_x(), c4.get_round_y()},
            {m3.get_round_x(), m3.get_round_y()},
            {c5.get_round_x(), c5.get_round_y()},
            {c6.get_round_x(), c6.get_round_y()},
            {m4.get_round_x(), m4.get_round_y()},
            {c7.get_round_x(), c7.get_round_y()},
            {c8.get_round_x(), c8.get_round_y()},
            {m1.get_round_x(), m1.get_round_y()}
        };
        setlinecolor(GREEN);
        polybezier(points, 13);
//        setlinecolor(WHITE);
//        polyline(points, 13);
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
        renderer->a1 = Vec2(-radius / 2, -radius / 2) + anchor;
        renderer->a2 = Vec2(-radius / 2, radius / 2) + anchor;
        renderer->a3 = Vec2(radius / 2, radius / 2) + anchor;
        renderer->a4 = Vec2(radius / 2, -radius / 2) + anchor;
        renderer->apply_transform(update_world_transform());
        return renderer;
    }
};


#endif //SUPERKK_CIRCLENODE_H
