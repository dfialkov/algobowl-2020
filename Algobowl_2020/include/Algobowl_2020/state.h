/*
 * Authors: Chris Muller, Charles Gougenheim
 */

#ifndef STATE_H
#define STATE_H

#include <Algobowl_2020/point.h>
#include <vector>
#include <set>

class State {
public:
    State(int k, std::vector<Point> points);
    void step(int src, int dest);
    int get_max_dist();
    void debug();
private:
    std::vector<std::vector<Point>> sets;
    std::vector<Point> orphans;
    int max_dist;
};

#endif