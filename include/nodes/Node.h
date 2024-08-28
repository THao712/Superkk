#ifndef SUPERKK_NODE_H
#define SUPERKK_NODE_H

#include <vector>

#include "../utils/Vec2.h"
#include "../utils/Transform.h"

class Node {
protected:
    bool invalid;

    Transform world_transform;
    Transform transform;

    Vec2 anchor;

    int z_index;
    std::vector<Node*> children;
    Node* parent;

    const Transform & update_world_transform();
    void validate() {
        invalid = false;
    };
    void invalidate() {
        invalid = true;
    };
    void set_z_index(int z_index);
    void invalidate_children();

  public:
    Node()
        : transform(),
          world_transform(),
          z_index(0),
          parent(nullptr),
          invalid(true){}

    void add_child(Node* child, int z_index);
    const Vec2 &get_position() const;
    const Vec2 &get_scale() const;
    double get_angle() const;
    const Vec2 & get_world_position();
    void set_position(const Vec2 &position);
    void set_scale(const Vec2 &scale);
    void set_angle(double angle);
    void set_anchor(const Vec2 &anchor);
};

#endif  //SUPERKK_NODE_H
