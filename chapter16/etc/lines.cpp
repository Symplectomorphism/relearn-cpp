#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <stdexcept>
#include <vector>

using namespace Graph_lib;

int main() {
    const Point tl {6000, 640};

    Simple_window win1 {tl, 1200, 800, "lines"};
    // Simple_window win1 {tl, 1200, 800, "two lines"};

    // Line horizontal {Point{200, 200}, Point{400, 200}};
    // Line vertical {Point{300,100}, Point{300, 300}};

    Lines x;
    x.add(Point{200, 200}, Point{400, 200});
    x.add(Point{300, 100}, Point{300, 300});

    win1.attach(x);
    
    win1.wait_for_button();
}
