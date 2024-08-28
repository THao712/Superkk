#include <algorithm>

#include "../../include/nodes/Node.h"


void Node::add_child(Node* child, int z_index) {
    child->set_z_index(z_index);
    child->parent = this;
    auto it = std::lower_bound(children.begin(), children.end(), child, [](Node* a, Node* b) {
        return a->z_index < b->z_index;
    });
    children.insert(it, child);
}

const Transform & Node::update_world_transform() {
    if (!invalid) {
        return world_transform;
    }
    world_transform = transform;
    if (parent == nullptr) {
        validate();
        return world_transform;
    }
    const Transform &parent_transform = parent->update_world_transform();
    world_transform.apply(parent_transform);
    validate();
    return world_transform;
}

void Node::set_z_index(int z_index) {
    this->z_index = z_index;
}

const Vec2 &Node::get_position() const {
    return transform.get_translation();
}

void Node::set_position(const Vec2 &position) {
    invalidate_children();
    this->transform.set_position(position);
}

const Vec2 &Node::getScale() const {
    return transform.get_scale();
}

void Node::set_scale(const Vec2 &scale) {
    invalidate_children();
    this->transform.set_scale(scale);
}

void Node::invalidate_children() {
    invalidate();
    for (auto child : children) {
        child->invalidate();
    }
}

Vec2 Node::get_world_position() {
    return update_world_transform().get_translation();
}

void Node::set_angle(double angle) {
    invalidate_children();
    transform.setAngle(angle);
}

void Node::set_anchor(const Vec2 &anchor) {
    invalidate_children();
    transform.setAnchor(anchor);
}
