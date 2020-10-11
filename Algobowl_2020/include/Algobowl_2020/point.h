/*
 * Authors: Chris Muller
 */

#ifndef POINT_H
#define POINT_H

struct Point {
    int x, y, z;

    //constructor
    Point(int x, int y, int z);

    //compare 2 points (for the sake of priority_queue)
    static bool compare(Point p1, Point p2);

    //calculate manhattan distance between p1 and p2
    static int calc_manhat_dist(Point p1, Point p2);
};

#endif
