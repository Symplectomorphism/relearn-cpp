#include "../include/std_lib_facilities.h"

class Bad_area {};      // a type specifically for reporting errors from area()

// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument
int area(int length, int width)
{
    if (length <= 0 || width <= 0) error("area() pre-condition");
    int a = length * width;
    cout << a << endl;
    if (a <= 0) error("area() post-condition");
    return a;
}


int framed_area(int x, int y)
{
    constexpr int frame_width = 2;
    return area(x-frame_width, y-frame_width);
}

int main()
{
    try {
        int x = 1;
        int y = 2;
        int z = 4;

        int area1 = area(x, y);
        int area2 = framed_area(1, z);
        int area3 = framed_area(y, z);
        double ratio = double(area1)/area3;
        
        cout << "ratio: " << ratio << '\n';
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}
