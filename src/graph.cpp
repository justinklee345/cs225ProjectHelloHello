#include "graph.h"
#include <bits/stdc++.h>

Graph::Graph() {
    vector<vector<int>> source;
    for (int SOURCE=0; SOURCE<0; SOURCE++) {
        vector<int> targets;
        for (int TARGET=0; TARGET<0; TARGET++) {
            targets.push_back(0);
        }
        source.push_back(targets);
    }
}

// populate adjacency matrix with dataset
Graph::Graph(const string& filename) {
    vector<vector<int>> source;
    for (int SOURCE=0; SOURCE<7604; SOURCE++) {
        vector<int> targets;
        for (int TARGET=0; TARGET<7604; TARGET++) {
            targets.push_back(0);
        }
        source.push_back(targets);
    }
    // initialized default matrix
    adj_matrix = source;
    cout << "initialized default matrix" << endl;

    // create file input stream
    ifstream input(filename);
    cout << "created file input stream" << endl;

    if (!input.is_open()) {
        cout << "file isn't open" << endl;
    }
    if (!input) {
    perror("open failure");
    }

    // ensure file is open
    if (input.is_open()) {
        cout << "file is open" << endl;
        // read in lines from file
        string line;
        // get column names
        getline(input, line);

        cout << "header: " << line << endl;
        int SOURCE, TARGET, RATING, TIME;
        while (getline(input, line)) {
            // cout << "line: " << line << endl;
            // create line string stream
            stringstream str_stream(line);
            str_stream >> SOURCE;
            str_stream.ignore();
            str_stream >> TARGET;
            str_stream.ignore();
            str_stream >> RATING;
            str_stream.ignore();
            str_stream >> TIME;
            // so that negative ratings are weighted higher
            RATING = RATING * -1;
            // so that ratings go from 1 to 21 since 0 represents no rating
            RATING = RATING + 11;
            // now a rating of -10 is 21, having the greatest weight, and a rating of 10 is 1, having the least weight
            // thus, the path with the greatest distance will be the least reliable transaction path
            cout << "insert " << RATING << " into [" << SOURCE << "][" << TARGET << "]" << endl;
            adj_matrix[SOURCE][TARGET] = RATING;


        }
    }
    input.close();
}


void Graph::print() {
    for (int SOURCE=0; SOURCE<7604; SOURCE++) {
        for (int TARGET=0; TARGET<7604; TARGET++) {
            cout << adj_matrix[SOURCE][TARGET] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int Graph::getRating(int src, int target) {
    return adj_matrix[src][target];
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

vector<int> Graph::bfs(int src) {
    vector<int> path;
    vector<bool> visited;
    for (int i=0; i<7604; i++) {
        visited.push_back(false);
    }
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty()) {
        int curr = q.front();
        path.push_back(curr);
        q.pop();
        for (int target=0; target<(int)adj_matrix[curr].size(); target++) {
            if (adj_matrix[curr][target] >= 1 && visited[target]==false) {
                q.push(target);
                visited[target] = true;
            }
        }
    }
    return path;
}