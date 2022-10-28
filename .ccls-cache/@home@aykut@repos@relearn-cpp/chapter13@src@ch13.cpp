#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <stdexcept>
#include <vector>

using namespace Graph_lib;

int main() {
    const Point tl {6000, 640};

    Simple_window win1 {tl, 1200, 800, "fat dashed red grid"};

    int x_size = win1.x_max();
    int y_size = win1.y_max();
    int x_grid = 160;
    int y_grid = 80;

    Lines grid;
    for (int x=x_grid; x<x_size; x+=x_grid)
        grid.add(Point{x,0}, Point{x,y_size});  // vertical line
    for (int y=y_grid; y<y_size; y+=y_grid)
        grid.add(Point{0, y}, Point{x_size,y});  // horizontal line
    grid.set_color(Color::red);
    grid.set_style(Line_style{Line_style::dash, 2});
    win1.attach(grid);

    Open_polyline opl = {
        {200, 200}, {300, 400}, {500, 500}, {600, 400}
    };
    // Open_polyline opl;
    // Polygon poly = {
    //     {200, 200}, {300, 400}, {500, 500}, {600, 400}
    // };
    // poly.add(Point{300,200});
    // poly.add(Point{350,100});
    // poly.add(Point{400,200});
    
    // Lines poly = {
    //     {Point{100,100}, Point{200,100}},
    //     {Point{150,50}, Point{150,150}}
    // };
    // Lines x = {
    //     {{100,100}, {200,100}},
    //     {{150,50}, {150,150}}
    // };
    // Closed_polyline cpl = {
    //     {200, 200}, {300, 400}, {500, 500}, {600, 400}
    // };
    // win1.attach(cpl);
    
    win1.attach(opl);

    win1.wait_for_button();
}
