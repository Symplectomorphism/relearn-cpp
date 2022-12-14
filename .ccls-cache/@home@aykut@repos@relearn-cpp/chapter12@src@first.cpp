#include "../include/Simple_window.h"
#include "../include/Graph.h"

int main() {
    using namespace Graph_lib;      // our graphics facilities are in Graph_lib

    Point tl {100, 100};            // to become top left corner of window

    Simple_window win {tl, 600, 400, "Canvas"};     // make a simple window

    Polygon poly;                   // make a shape (a polygon)

    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);     // adjust properties of poly

    win.attach (poly);              // connect poly to the window

    win.wait_for_button();          // give control to the display engine
}
