#ifndef SUPERKK_RENDERABLENODE_H
#define SUPERKK_RENDERABLENODE_H


#include "Node.h"
#include "../renderer/RenderPipeline.h"
#include "../renderer/Renderer.h"

class RenderableNode : public Node {
public:
    virtual Renderer* get_renderer() = 0;
};


#endif //SUPERKK_RENDERABLENODE_H
