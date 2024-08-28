#ifndef SUPERKK_RENDERER_H
#define SUPERKK_RENDERER_H


#include "../utils/Vec2.h"
#include "../utils/Transform.h"
/**
 * 保存可渲染节点的渲染逻辑, 通过继承实现不同的渲染逻辑
 */
class Renderer {
public:
    virtual void render() = 0;
    virtual void apply_transform(const Transform& transform) = 0;
};


#endif //SUPERKK_RENDERER_H
