#include <graphics.h>
#include <conio.h>
#include "../include/nodes/Node.h"
#include "../include/nodes/CircleNode.h"

int main() {
    initgraph(800, 800);
    Node root;
    CircleNode circle_node(60);
    circle_node.set_position({200, 200});
    circle_node.set_anchor({100, 100});
    for (int i = 0; i < 50; ++i) {
//        circle_node.set_scale({1 + i * 0.1, 1 + i * 0.1});
        circle_node.set_angle(i * 3);
        Renderer *renderer = circle_node.get_renderer();
        renderer->render();
        Sleep(100);
    }
    getch();
    closegraph();
    return 0;
}