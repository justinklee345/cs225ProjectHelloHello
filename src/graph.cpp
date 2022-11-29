#include "graph.h"

Graph::Graph() {
    vector<vector<int>> source;
    for (int SOURCE=1; SOURCE<=7604; SOURCE++) {
        vector<int> targets;
        for (int TARGET=1; TARGET<=7604; TARGET++) {
            targets.push_back(0);
        }
        source.push_back(targets);
    }
}

// populate adjacency matrix with dataset
Graph::Graph(const string& filename) {
    vector<vector<int>> source;
    for (int SOURCE=1; SOURCE<=7604; SOURCE++) {
        vector<int> targets;
        for (int TARGET=1; TARGET<=7604; TARGET++) {
            targets.push_back(0);
        }
        source.push_back(targets);
    }

    // create file input stream
    ifstream input(filename);

    // ensure file is open 
    if (input.is_open()) {
        // read in lines from file
        string line;
        // get column names
        getline(input, line);
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
            adj_matrix[SOURCE][RATING] = RATING;
        }
    }
    input.close();
}

void Graph::print() {
    for (int SOURCE=1; SOURCE<=7604; SOURCE++) {
        for (int TARGET=1; TARGET<=7604; TARGET++) {
            cout << adj_matrix[SOURCE][TARGET] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int Graph::dijkstra(int src, int target) const {
    vector<int> distance(adj_matrix.size(), INT_MAX);
    vector<bool> incShort(adj_matrix.size(), false);

    distance[src] = 0;
    for (int i = 0; i < (int)adj_matrix[0].size() - 1; ++i) {
        int mindist = minDistance(distance, incShort);
        incShort[mindist] = true;
        for (int node = 0; node < (int)adj_matrix[0].size(); ++node) {
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
    for (int node = 0; node < (int)adj_matrix[0].size(); ++node) {
        if (!incShort.at(node) && distance.at(node) <= min) {
            min = distance.at(node);
            min_idx = node;
        }
    }
    return min_idx;
}