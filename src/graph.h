#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <bits/stdc++.h>

using namespace std;
class Graph {
  	public:
		Graph();
    	Graph(const string& filename);
		int dijkstra(int src, int target) const;
		void print();
		int getRating(int src, int target);
	private:
		int minDistance(vector<int> distance, vector<bool> incShort) const;

		/*
		each element in the adj_matrix tells us only one direction...
		ex) if adj_matrix[0][1] == 1, vertex 0 follows vertex 1 (0 --> 1), but not the other way around
		*/
		vector<vector<int>> adj_matrix;
};
