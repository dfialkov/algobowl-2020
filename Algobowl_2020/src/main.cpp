/*
 * Authors: Chris Muller, Daniel Fialkov, Thomas Deisz, Charles Gougenheim
 */

#include <iostream>
#include <vector>
#include <fstream>
#include<queue>
#include <Algobowl_2020/point.h>
#include <Algobowl_2020/state.h>

using namespace std;

int main() {
    std::vector<Point> points;
    int num_points, num_sets;
    ifstream ifs;

    //access file
    ifs.open("input.txt", ios::in);
    if(!ifs.is_open()) {
        cout << "Could not open file" << endl;
        exit(1);
    }

    //read in number of points
    if(!(ifs >> num_points)) {
        cout << "File Format Error" << endl;
        exit(1);
    }

    //read in number of sets
    if(!(ifs >> num_sets)) {
        cout << "File Format Error" << endl;
        exit(1);
    }

    //read in n points
    for(int i = 0; i < num_points; i++) {
        int x, y, z;

        if(!(ifs >> x)) {
            cout << "File Format Error" << endl;
            exit(1);
        }
        if(!(ifs >> y)) {
            cout << "File Format Error" << endl;
            exit(1);
        }
        if(!(ifs >> z)) {
            cout << "File Format Error" << endl;
            exit(1);
        }

        //emplace combines push() and Point's constructor
        points.emplace_back(x, y, z);
    }
    ifs.close();




    //debugging
    State s(num_sets, points);
    s.debug();

    //debug copy constructor
    State debugCopyS = State(s);
    debugCopyS.debug();

    /*
    //Create queues
    queue<State> thisExplore;
    //Create a priority queue that has the state with the HIGHEST maxDist on top

    //Prepare a state that has one point in each state, selected more or less randomly.
    for(int i = 0;i<num_sets;i++){
        s.step(i, i);
    }
    cout << "Initial state: " << endl;
    s.debug();


    //Place this state into thisExplore
    thisExplore.push(s);

    //while thisExplore is not empty:
    while (!thisExplore.empty()){

      State myState = thisExplore.pop();
      for(int i = 0;i<myState.getOrphansSize();i++){
        for(int j = 0;j<num_sets;j++){

        }
      }
    }
    //Pop state newS off the top of thisExplore

    //For each item in the orphan set of newS:
        //For each set of points in newS:
            //create a copy of newS
            //Move the item into the set
*/
}
