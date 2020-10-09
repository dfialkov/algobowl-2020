#include <Algobowl_2020/point.h>
#include <stdlib.h>

//constructor implementation
Point::Point(int x, int y, int z): x(x), y(y), z(z) {};

//member function implementation
int Point::calc_manhat_dist(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}