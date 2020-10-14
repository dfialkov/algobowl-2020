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


struct CompareMaxDist{
  bool operator()(State const& s1, State const& s2){
    return s1.get_max_dist() < s2.get_max_dist();
  }
};

struct CompareReturnZero{
  bool operator()(State const& s1, State const& s2){
    return 0;
  }
};


int main() {
    std::vector<Point> points;
    int num_points, num_sets;
    ifstream ifs;

    //Beam size. You can change this for a bigger beam(more memory) or a smaller beam(less memory)
    int beamSize = 1000;

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





    //Create queues
    priority_queue <State, vector<State>, CompareMaxDist> thisExplore;
    //Create a priority queue that has the state with the HIGHEST maxDist on top
    priority_queue<State, vector<State>, CompareMaxDist> nextExplore;



    //Prepare a state that has one point in each state, selected more or less randomly.
    for(int i = 0;i<num_sets;i++){
        s.step(i, i);
    }
    cout << "Initial state: " << endl;
    s.debug();


    //Place this state into thisExplore
    thisExplore.push(s);
    //Generate expansions of the state(try to place every point in the orphan set into every set of the set of sets).
    // Place expansions into nextExplore.



    //while thisExplore is not empty:
    while (!thisExplore.empty()){
      //Get a state off the top
      State myState = thisExplore.top();
      thisExplore.pop();
      for(int i = 0;i<myState.getOrphansSize();i++){
        for(int j = 0;j<num_sets;j++){
          State expansionState = State(myState);
          expansionState.step(i, j);
          nextExplore.push(expansionState);
          if(nextExplore.size() > beamSize){
            nextExplore.pop();
          }
          //First, check if the top item of nextExplore has an orphan set of size zero. If it is, break out of this this for loop
          if(nextExplore.top().getOrphansSize()==0){
            break;
          }
          //Otherwise, transfer the contents of nextExplore into thisExplore.
          else{
            nextExplore.swap(thisExplore);
            //However you do that, make sure that nextExplore is empty before the while loop continues.
            //Then, let the while loop continue
            while (!nextExplore.empty()){
              nextExplore.pop();
            }
          }
        }
      }

      //Info on what to do after breaking out is directly after the end of this while loop
  }
  //Once you've broken out, place the contents of nextExplore into a vector of states.
  std::vector<State> finalAnswer;
  int index = 0;
  int minMaxDist=1000000;
  int possibleMin;
  while (!nextExplore.empty()){
    finalAnswer.push_back(nextExplore.top());
    nextExplore.pop();
    index++;
  }
      //The output is the state in this array that has the lowest MaxDist.

    for(int i = 0;i<index;i++){
        possibleMin = finalAnswer[i].get_max_dist();

        if((possibleMin < minMaxDist) || minMaxDist==0){
          minMaxDist = possibleMin;
        }
    }

    //Write the output to a file? I don't know what form the output is supposed to be in.
    //Shouldn't be hard to find out though.
    ofstream fout;
    fout.open("answer.txt");
    fout<< minMaxDist <<endl;
    fout<< possibleMin <<endl;
    fout.close();


    //Remember to tweak the beam size

}
