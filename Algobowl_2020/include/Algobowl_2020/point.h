#ifndef POINT_H
#define POINT_H

struct Point {
    int x, y, z;

    //create new point
    Point(int x, int y, int z); 
    
    //calculate manhattan distance between p1 and p2
    static int calc_manhat_dist(Point p1, Point p2);
};

#endif