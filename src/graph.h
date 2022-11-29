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
		void addEdge(string from, string to, int weight);
		int dijkstra(string src, string target) const;
	private:
		void populateMatrix(vector<pair<pair<string, string>, int>> edges);
		int minDistance(vector<int> distance, vector<bool> incShort) const;
		int get_id(string src) const;
		map<string, int> nodeID_map;

		/*
		each element in the adj_matrix tells us only one direction...
		ex) if adj_matrix[0][1] == 1, vertex 0 follows vertex 1 (0 --> 1), but not the other way around
		*/
		vector<vector<int>> adj_matrix;
		int num_nodes_;
};
