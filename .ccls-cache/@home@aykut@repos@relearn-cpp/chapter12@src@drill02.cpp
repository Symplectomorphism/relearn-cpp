#include "Simple_window.h"
#include "Graph.h"
#include <stdexcept>

using namespace Graph_lib;

int main() {
    Point tl {3000, 500};        // top left corner of our window

    Simple_window win {tl, 600, 400, "Canvas"};
        // screen coordinate tl for top left corner
        // window size(600-by-400)
        // title: Canvas
    
    Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};   // make an Axis
        // an Axis is a kind of Shape
        // Axis::x means horizontal
        // starting at (20,300)
        // 280 pixels long
        // 10 "notches"
        // label the axis "x axis"
    win.attach(xa);                 // attach xa to the window, win
    win.set_label("Canvas #2");     // relabel the window     

    Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");

    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};  // sine curve
        // plot sin() in the range [0:100) with (0,0) at (20,150)
        // using 1000 points; scale x values *50, scale y values *50
    win.attach(sine);
    win.set_label("Canvas #4");

    sine.set_color(Color::blue);        // we changed our mind about sine's
                                        // color
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("Canvas #5");

    Rectangle r {Point{200,200}, 100, 50};      // top left corner, width,
                                                // height
    win.attach(r);
    win.set_label("Canvas #6");

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);        // color the inside of the rectangle
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("Canvas #7");

    Text t {Point{150, 150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("Canvas #8");

    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(20);
    win.set_label("Canvas #9");
    
    Image ii {Point{100, 50}, "sound-barrier-resized.jpg"};
    win.attach(ii);
    win.set_label("Canvas #10");

    // r.move(100, -100);

    ii.move(100, 200);
    win.set_label("Canvas #11");

    Circle c {Point{100, 200}, 50};
    Ellipse e {Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m {Point{100, 200}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100, 20}, oss.str()};

    Image cal {Point{255, 225}, "snow_cpp.gif"};
    cal.set_mask(Point{40, 40}, 200, 150);

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.set_label("Canvas #12");

    win.wait_for_button();      // display!
}
