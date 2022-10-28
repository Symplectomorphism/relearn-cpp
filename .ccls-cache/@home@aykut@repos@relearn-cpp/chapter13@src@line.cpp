#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <stdexcept>
#include <vector>

using namespace Graph_lib;

int main() {
    const Point x {6000, 640};

    Simple_window win1 {x, 1200, 800, "two lines"};

    Line horizontal {Point{200, 200}, Point{400, 200}};
    Line vertical {Point{300,100}, Point{300, 300}};

    win1.attach(horizontal);
    win1.attach(vertical);
    
    win1.wait_for_button();
}
