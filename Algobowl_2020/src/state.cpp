#include <Algobowl_2020/state.h>
#include <iostream>

using namespace std;

State::State(int k, std::vector<Point> points) {
    // instantiate k empty sets
    for(int i = 0; i < k; i++)  {
        sets.emplace_back();
    }
    // populate orphans
    orphans = std::vector<Point>(points);
}

void State::step(int src, int dest) {
    // update max dist
    for(Point p : sets[dest]) {
        int dist = Point::calc_manhat_dist(orphans[src], p);
        if(dist > max_dist) {
            max_dist = dist;
        }
    }
    // move element at orphans[src] into vec at sets[dest]
    sets[dest].push_back(std::move(orphans[src]));
    // remove element from orphans
    orphans.erase(orphans.begin() + src);
}

int State::get_max_dist() {
    return max_dist;
}

void State::debug() {
    for(int i = 0; i < sets.size(); i++) {
        std::cout << "Set " << i << ": ";
        for(int j = 0; j < sets[i].size(); j++) {
            std::cout << "(" << sets[i][j].x << ", " << sets[i][j].y << ", " << sets[i][j].z << "), ";
        }
        std::cout << endl;
    }
    std::cout << endl << "orphans: ";
    for(int l = 0; l < orphans.size(); l++) {
        std::cout << "(" << orphans[l].x << ", " << orphans[l].y << ", " << orphans[l].z << "), ";
    }
    std::cout << endl << endl;
}
