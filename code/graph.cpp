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
