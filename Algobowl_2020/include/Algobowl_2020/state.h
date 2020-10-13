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
    State(const State& toCopy);
    void step(int src, int dest);
    int get_max_dist() const;
    int getOrphansSize() const;
    std::vector<std::vector<Point>> getSets() const;
    Point getOrphanIdx(int idx) const;
    void debug();
private:
    std::vector<std::vector<Point>> sets;
    std::vector<Point> orphans;
    int max_dist;
};

#endif
