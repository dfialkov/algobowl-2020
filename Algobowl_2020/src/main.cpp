/*
 * Authors: Chris Muller, Daniel Fialkov, Thomas Deisz, Charles Gougenheim
 */

#include <iostream>
#include <queue>
#include <fstream>
#include <functional>
#include <Algobowl_2020/point.h>

using namespace std;

int main() {
    priority_queue<Point, std::vector<Point>, std::function<bool(Point, Point)>> points(Point::compare);
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
        points.emplace(x, y, z);
    }

    ifs.close();

    //debugging
    cout << "number of points: " << num_points << endl;
    cout << "number of sets: " << num_sets << endl;
    cout << "top point x: " << points.top().x << endl;
}