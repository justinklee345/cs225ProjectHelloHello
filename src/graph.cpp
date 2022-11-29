#include "graph.h"
#include <bits/stdc++.h>

// populate adjacency matrix with dataset
Graph::Graph(const string& filename) {
    // create file input stream
    ifstream input(filename);

    // ensure file is open
    if (input.is_open()) {
        // read in lines from file
        string line;
        // get column names
        getline(input, line);
        cout << "Got to here!" << endl;
        int SOURCE, TARGET, RATING, TIME;
        while (getline(input, line)) {
            // create line string stream
            stringstream str_stream(line);
            str_stream >> SOURCE;
            str_stream.ignore();
            str_stream >> TARGET;
            str_stream.ignore();
            str_stream >> RATING;
            str_stream.ignore();
            str_stream >> TIME;
            // put rating in adjacency matrix
            adj_matrix[SOURCE][TARGET] = RATING;
            cout << adj_matrix[SOURCE][TARGET] << endl;
        }
    }
    input.close();
}

int Graph::dijkstra(int src, int target) const {
    vector<int> distance(adj_matrix.size(), INT_MAX);
    vector<bool> incShort(adj_matrix.size(), false);

    distance[src] = 0;
    for (size_t i = 0; i < adj_matrix[0].size() - 1; ++i) {
        int mindist = minDistance(distance, incShort);
        incShort[mindist] = true;
        for (size_t node = 0; node < adj_matrix[0].size(); ++node) {
            if (!incShort.at(node) && adj_matrix[mindist][node] != 0) {
                if (distance.at(mindist) != INT_MAX && distance.at(mindist) + adj_matrix[mindist][node] < distance.at(node)) {
                    distance[node] = distance[mindist] + adj_matrix[mindist][node];
                }
            }
        }
    }
    return distance[target];
}

int Graph::minDistance(vector<int> distance, vector<bool> incShort) const {
    int min = INT_MAX;
    int min_idx = -1;
    for (size_t node = 0; node < adj_matrix[0].size(); ++node) {
        if (!incShort.at(node) && distance.at(node) <= min) {
            min = distance.at(node);
            min_idx = node;
        }
    }
    return min_idx;
}

const vector<vector<int>>& Graph::getMatrix() const {
    return adj_matrix;
}