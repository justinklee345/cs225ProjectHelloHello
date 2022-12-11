#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <bits/stdc++.h>
#include <queue>

using namespace std;
class Graph {
  	public:
		Graph();
    	Graph(const string& filename, int size);
		int dijkstra(int src, int target) const;
		const vector<vector<int>>& getMatrix() const;
		void print();
		int getRating(int src, int target);
		vector<int> bfs(int src);
		int trust(int src, int target);

		bool kosaraju(int src, int target);
		void fillOrder(int x, vector<bool> & visited, stack<int> & s);
		vector<vector<int>> getTranspose(vector<vector<int>> adj_matrix);
		void DFSU(int x, vector<bool> & visited, vector<int> & scc, vector<vector<int>> rev_adj_matrix);
	private:
		int minDistance(vector<int> distance, vector<bool> incShort) const;

		vector<vector<int>> adj_matrix;
		int size_;
		/*
		each element in the adj_matrix tells us only one direction...
		ex) if adj_matrix[0][1] == 1, vertex 0 follows vertex 1 (0 --> 1), but not the other way around
		*/
};
