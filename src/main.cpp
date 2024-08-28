#include <graphics.h>
#include <conio.h>
#include "../include/nodes/Node.h"
#include "../include/nodes/CircleNode.h"

int main() {
    initgraph(800, 800);
    Node root;
    CircleNode circle_node(100);
    circle_node.set_anchor({50, 0});
    circle_node.set_position({400, 400});
    for (int i = 0; i < 360 + 180; i += 10) {
        circle_node.set_angle(i / 180.0 * atan(1) * 4);
        circle_node.set_scale({i / 36.0 / 4.0, 1});
        Renderer *renderer = circle_node.get_renderer();
        renderer->render();
        Sleep(1);
    }
    getch();
    closegraph();
    return 0;
}