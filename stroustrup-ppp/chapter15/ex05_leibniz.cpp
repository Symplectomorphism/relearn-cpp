#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

#include <iostream>

using namespace Graph_lib;

double term(int n)
    // provide the appropriate Leibniz term w/correct sign
{
    int denom = 2 * n + 1;
    denom *= n % 2 == 0 ? 1 : -1;

    return 1.0 / denom;
}

double leibniz(int n)
{
    double sum = 0;

    for (int i = 0; i <= n; ++i)     // sum up terms upto n
        sum += term(i);

    return sum;
}

int main()
try {
    // Boilerplate
    constexpr int xmax = 600;
    constexpr int ymax = 400;
    constexpr int xc = xmax / 2;
    constexpr int yc = ymax / 2;
    constexpr int xscale = 20;
    constexpr int yscale = 20;
    constexpr int xlength = xmax - 40;
    constexpr int ylength = ymax - 40;

    Simple_window win {Point{100, 100}, xmax, ymax, "Chapter 15"};

    Axis x {Axis::x, Point{20, yc},
            xlength, xlength/xscale, "x"};
    Axis y {Axis::y, Point{xc, ylength + 20},
            ylength, ylength/yscale, "y"};
    x.set_color(Color::dark_red);
    y.set_color(Color::dark_red);

    win.attach(x);
    win.attach(y);
    win.wait_for_button();

    // Ex 5 - Leibniz
    constexpr double r_min = -10;
    constexpr double r_max = 11;
    const Point origin {xc, yc};

    for (int n = 0; n < 20; ++n) {
        ostringstream ss;
        ss << "exp approximation: n==" << n;
        win.set_label(ss.str());
        // get next approximation
        Function e {[n](double) { return leibniz(n); },
                r_min, r_max, origin, 200, xscale, yscale};
        win.attach(e);
        win.wait_for_button();
        win.detach(e);
    }

    win.wait_for_button();
}
catch (exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown exception\n";
    return 2;
}
/* Compile command
g++ -w -Wall -std=c++11 ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp ex05_leibniz.cpp `fltk-config --ldflags --use-images` -o a.out
*/
