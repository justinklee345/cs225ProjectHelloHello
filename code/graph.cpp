#include "graph.h"

Graph::Graph(const string& filename) {
    ifstream wordsFile(filename);
    string line;
    int count=0;
    if (wordsFile.is_open()) {
        // reads in line from filename
        while (!wordsFile.eof()) {
            // get from and to nodeIds
            string from_id;
            wordsFile >> from_id;
            string to_id;
            wordsFile >> to_id;
            // map id to count (making sure count is unique)
            if (!nodeID_map.count(from_id)) {
                nodeID_map[from_id]=count;
                count++;
            }
            if (!nodeID_map.count(to_id)) {
                nodeID_map[from_id]=count;
                count++;
            }
            if (wordsFile.eof()) break;
        }
    }
    // populate this vector of pairs of strings from the data!
    std::vector<pair<pair<string, string>, int>> edges;
    populateMatrix(edges);
    num_nodes_ = adj_matrix.size();
}

void Graph::addEdge(int from, int to, int weight) {
    if (from < 0 || from > num_nodes_ || to < 0 || to > num_nodes_) {
        // at least one of these nodes don't exist
        // this shouldn't be a problem since we are adding edges only at the beginning and we check the vertices in populateMatrix func.
        return;
    }
    adj_matrix[from][to] = weight;
}

// void Graph::populateMatrix(vector<pair<pair<string, string>, int>> edges) {
//     for (const auto& edge : edges) {
//         if (nodeID_map.find(edge.first.first) == nodeID_map.end() || nodeID_map.find(edge.first.second) == nodeID_map.end()) {
//         // this means that we failed to add all the vertices in to the NodeID_map prior to calling this function.
//             return;
//         }
//         addEdge(edge.first.first, edge.first.second, edge.second);
//     }
// }

int Graph::dijkstra(int src, int target) const {
    vector<int> distance(adj_matrix.size(), INT_MAX);
    vector<bool> incShort(adj_matrix.size(), false);

    distance[src] = 0;
    for (int i = 0; i < num_nodes_ - 1; ++i) {
        int mindist = minDistance(distance, incShort);
        incShort[mindist] = true;
        for (int node = 0; node < num_nodes_; ++node) {
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
    for (int node = 0; node < num_nodes_; ++node) {
        if (!incShort.at(node) && distance.at(node) <= min) {
            min = distance.at(node);
            min_idx = node;
        }
    }
    return min_idx;
}