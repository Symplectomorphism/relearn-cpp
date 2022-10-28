#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <stdexcept>
#include <vector>

using namespace Graph_lib;

int main() {
    Point tl {6000, 640};        // top left corner of our window

    Simple_window win {tl, 1200, 800, "Canvas"};

    Rectangle r{Point{100, 100}, 100, 50};
    r.set_color(Color::blue);
    win.attach(r);

    Polygon rect;
    rect.add(Point{250, 100});
    rect.add(Point{350, 100});
    rect.add(Point{350, 150});
    rect.add(Point{250, 150});
    rect.set_color(Color::red);
    win.attach(rect);

    win.set_label("Chapter 12 Exercise 1");
    win.wait_for_button();

    Rectangle rt{Point{400, 100}, 200, 60};
    win.attach(rt);

    Text t {Point{405, 150}, "Howdy!"};
    t.set_font(Graph_lib::Font::helvetica_bold);
    t.set_font_size(20);
    win.attach(t);

    win.set_label("Chapter 12 Exercise 2");
    win.wait_for_button();

    // Exercise 4: draw a 3-by-3 tic-tac-toe board of alternating white and red
    // squares.
    Vector_ref<Rectangle> vr;
    int w = 100;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            vr.push_back(new Rectangle{Point{700+w*col, 400+w*row}, w, w});
            int i = vr.size() - 1;

            i % 2 == 0
                ? vr[i].set_fill_color(Color::red)
                : vr[i].set_fill_color(Color::white);

            win.attach(vr[i]);
        }
    }

    win.set_label("Chapter 12 Exercise 4");
    win.wait_for_button();
                                
    /*
    Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa); 
    win.set_label("Canvas #2"); 

    Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");

    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    win.attach(sine);
    win.set_label("Canvas #4");

    sine.set_color(Color::blue);

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.set_label("Canvas #5");

    Rectangle r {Point{200,200}, 100, 50};
    win.attach(r);
    win.set_label("Canvas #6");

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    win.attach(poly_rect);

    r.set_fill_color(Color::yellow);
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
    */
}
