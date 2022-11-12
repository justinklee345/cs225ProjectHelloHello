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
    std::vector<pair<string, string>> edges;
    populateMatrix(edges);
}

void Graph::addEdge(string from, string to) {
    if (nodeID_map.find(from) == nodeID_map.end() || nodeID_map.find(to) == nodeID_map.end()) {
        // at least one of these nodes don't exist
        // this shouldn't be a problem since we are adding edges only at the beginning and we check the vertices in populateMatrix func.
        return;
    }
    adj_matrix[nodeID_map[from]][nodeID_map[to]] = 1;
}

void Graph::populateMatrix(vector<pair<string, string>> edges) {
    for (const auto& edge : edges) {
        if (nodeID_map.find(edge.first) == nodeID_map.end() || nodeID_map.find(edge.second) == nodeID_map.end()) {
        // this means that we failed to add all the vertices in to the NodeID_map prior to calling this function.
            return;
        }
        addEdge(edge.first, edge.second);
    }
}