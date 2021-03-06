#include <Algobowl_2020/point.h>
#include <stdlib.h>

//constructor implementation
Point::Point(int x, int y, int z, int id): x(x), y(y), z(z) {};
Point::Point(const Point& p): x(p.x), y(p.y), z(p.z) , id(p.id){};

//defines behavior for the weak ordering of the priority_queue
bool Point::compare(Point p1, Point p2) {
    return p1.x < p2.x;
}

//calculate manhattan distance between p1 and p2
int Point::calc_manhat_dist(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}
