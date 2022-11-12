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
}

void Graph::addEdge(string from, string to) {
    if (nodeID_map.find(from) == nodeID_map.end() || nodeID_map.find(to) == nodeID_map.end()) {
        // at least one of these nodes don't exist
        // this shouldn't be a problem since we are adding vertices only at the beginning.
        return;
    }
    adj_matrix[nodeID_map[from]][nodeID_map[to]] = 1;
}