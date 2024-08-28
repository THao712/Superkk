#ifndef SUPERKK_RENDERER_H
#define SUPERKK_RENDERER_H


#include "../utils/Vec2.h"
#include "../utils/Transform.h"
/**
 * �������Ⱦ�ڵ����Ⱦ�߼�, ͨ���̳�ʵ�ֲ�ͬ����Ⱦ�߼�
 */
class Renderer {
public:
    virtual void render() = 0;
    virtual void apply_transform(const Transform& transform) = 0;
};


#endif //SUPERKK_RENDERER_H
