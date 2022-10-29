#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main() {
    constexpr int xmax = 1200;
    constexpr int ymax = 800;

    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;
    Point const orig {x_orig, y_orig};

    constexpr int r_min = -18;
    constexpr int r_max = 18;

    constexpr int n_points = 800;
    
    constexpr int x_scale = 30;
    constexpr int y_scale = 30;

    constexpr int xlength = xmax-40;
    constexpr int ylength = ymax-40;

    Simple_window win {Point{6000,640}, xmax, ymax, "Function graphing"};

    Function s {one, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function s2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function s3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};
    Function s4 {cos, r_min, r_max, orig, n_points, x_scale, y_scale};
    s4.set_color(Color::blue);
    Function s5 {sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};
    s5.set_color(Color::green);

    win.attach(s);
    win.attach(s2);
    win.attach(s3);
    win.attach(s4);
    win.attach(s5);

    Text ts {Point{100, y_orig-40}, "one"};
    Text ts2 {Point{100, y_orig+y_orig/2+10}, "x/2"};
    Text ts3 {Point{x_orig-150, 20}, "x*x"};
    
    win.attach(ts);
    win.attach(ts2);
    win.attach(ts3);

    Axis x {Axis::x, Point{20, y_orig},
        xlength, xlength/x_scale, "one_notch=1"};
    Axis y {Axis::y, Point{x_orig, ylength+20},
        ylength, ylength/y_scale, "one_notch=1"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    x.label.move(-320,0);
    x.notches.set_color(Color::dark_red);

    win.attach(x);
    win.attach(y);

    win.set_label("Function graphing: use color");
    win.wait_for_button();

    return 0;
}
