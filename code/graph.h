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
		void addEdge(string from, string to);
		// djikstra();
	private:
		void populateMatrix(vector<pair<string, string>> edges);
		map<string, int> nodeID_map;

		/*
		each element in the adj_matrix tells us only one direction...
		ex) if adj_matrix[0][1] == 1, vertex 0 follows vertex 1 (0 --> 1), but not the other way around
		*/
		vector<vector<int>> adj_matrix;
};
