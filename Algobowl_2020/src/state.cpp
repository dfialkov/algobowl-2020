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

State::State(const State& toCopy){
  //copy orphans
  for(int i = 0;i<toCopy.getOrphansSize();i++){
    orphans.emplace_back(Point(toCopy.getOrphanIdx(i)));
  }
  //copy maxDist
  max_dist = toCopy.get_max_dist();

  //for every subset in the copied state's sets...
  for(vector<Point> srcSet : toCopy.getSets()){
    //create a subset in the new state
    std::vector<Point> subset;
    //for every point in the subset...
    for(Point srcPoint: srcSet){
      //copy the point and push it into the new set's subset
      subset.emplace_back(Point(srcPoint));
    }
    //place the subset into the new state's sets
    sets.push_back(subset);


  }
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

int State::get_max_dist() const{
    return max_dist;
}

int State::getOrphansSize() const{
  return orphans.size();
}

Point State::getOrphanIdx(int idx)const{
  return orphans[idx];
}

std::vector<std::vector<Point>> State::getSets()const{
  return sets;
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
