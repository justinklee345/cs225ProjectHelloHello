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
		// default constructor
		Graph();

		// constructor for populating the adj. matrix from our dataset
    	Graph(const string& filename, int size);

		// standard getter methods for the rating and the entire adj. matrix
		int getRating(int src, int target);
		const vector<vector<int>>& getMatrix() const;

		// print adj. matrix
		void print();

		// bfs
		vector<int> bfs(int src);

		// dijkstra function
		int dijkstra(int src, int target) const;

		// kosaraju function
		bool kosaraju(int src, int target);

		// final output
		bool trust(int src, int target);

	private:
		// helper function for Dijkstra's Algo.
		int minDistance(vector<int> distance, vector<bool> incShort) const;

		// helper function for Kosaraju's Algo
		vector<vector<int>> getTranspose(vector<vector<int>> adj_matrix);
		void fillOrder(int x, vector<bool> & visited, stack<int> & s);
		void DFSU(int x, vector<bool> & visited, vector<int> & scc, const vector<vector<int>>& rev_adj_matrix);

		/*
		each element in the adj_matrix tells us only one direction...
		ex) if adj_matrix[0][1] == 1, vertex 0 follows vertex 1 (0 --> 1), but not the other way around
		*/
		vector<vector<int>> adj_matrix;

		// num. of unique id's
		int size_;
};
