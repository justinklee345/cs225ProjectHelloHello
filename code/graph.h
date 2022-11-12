#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
class Graph {
  public:
    Graph(const string& filename);
  private:
    // vector<int> maze_;
    map<string, int> nodeID_map;
};
