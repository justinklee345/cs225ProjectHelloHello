#include "graph.h"
#include <bits/stdc++.h>

// just a default constructor setting all values in the adj. matrix to be 0.
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
Graph::Graph(const string& filename, int size) {
    size_ = size;
    vector<vector<int>> source;
    for (int SOURCE=0; SOURCE<size_; SOURCE++) {
        vector<int> targets;
        for (int TARGET=0; TARGET<size_; TARGET++) {
            targets.push_back(0);
        }
        source.push_back(targets);
    }
    // initialized default matrix
    adj_matrix = source;
    // cout << "initialized default matrix" << endl;
    // create file input stream

    ifstream input(filename);
    // cout << "created file input stream" << endl;

    if (!input.is_open()) {
        cout << "file isn't open" << endl;
    }
    if (!input) {
    perror("open failure");
    }

    // ensure file is open
    if (input.is_open()) {
        // cout << "file is open" << endl;
        // read in lines from file
        string line;
        // get column names
        getline(input, line);

        // cout << "header: " << line << endl;
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
            // cout << "insert " << RATING << " into [" << SOURCE << "][" << TARGET << "]" << endl;
            adj_matrix[SOURCE][TARGET] = RATING;
        }
    }
    input.close();
}

int Graph::getRating(int src, int target) {
    return adj_matrix[src][target];
}

const vector<vector<int>>& Graph::getMatrix() const {
    return adj_matrix;
}

void Graph::print() {
    for (int SOURCE=0; SOURCE<size_; SOURCE++) {
        for (int TARGET=0; TARGET<size_; TARGET++) {
            cout << adj_matrix[SOURCE][TARGET] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> Graph::bfs(int src) {
    vector<int> path;
    vector<bool> visited;
    for (int i=0; i<size_; i++) {
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
            if (adj_matrix[curr][target] > 0 && visited[target]==false) {
                q.push(target);
                visited[target] = true;
            }
        }
    }
    return path;
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

bool Graph::kosaraju(int src, int target) {
    vector<bool> visited;
    vector<vector<int>> rev_adj_matrix;
    stack<int> s;

    for (int i=0; i< size_; i++) {
        visited.push_back(false);
    }
    for (int i = 0; i < size_; i++) {
        if (!visited[i]) {
            fillOrder(i, visited, s);
        }
    }

    rev_adj_matrix = getTranspose(adj_matrix);

    for (int i=0; i< size_; i++) {
        visited[i] = false;
    }
    vector<vector<int>> output;
    int c = 0;

    while (!s.empty()) {
        // std::cout << c << std::endl;
        c++;
        int v = s.top();
        s.pop();
        if (!visited[v]) {
            vector<int> scc;
            DFSU(v, visited, scc, rev_adj_matrix);
            output.push_back(scc);
        }
    }

    for (int i = 0; i < (int)output.size(); i++) {
        if (std::find(output[i].begin(), output[i].end(), src) != output[i].end() &&
        std::find(output[i].begin(), output[i].end(), target) != output[i].end()) {
            return true;
        }
    }
    /*
    for testing and running the connected components
    std::cout << (int)output.size() << std::endl;
    for (int i = 0; i < (int)output.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < (int)output[i].size(); j++) {

            cout << output[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    */
    return false;
}

// helper function for kosaraju (returns the transposed adj. matrix for the reverse direction dfs that kosaraju uses)
vector<vector<int>> Graph::getTranspose(vector<vector<int>> adj_matrix) {
    vector<vector<int>> rev_adj_matrix;

    for (int SOURCE=0; SOURCE<size_; SOURCE++) {
        vector<int> targets;
        for (int TARGET=0; TARGET<size_; TARGET++) {
            targets.push_back(0);
        }
        rev_adj_matrix.push_back(targets);
    }

    for (int i = 0; i < (int)adj_matrix.size(); i++) {
        for (int j = 0; j < (int)adj_matrix[i].size(); j++) {
            rev_adj_matrix[i][j] =  adj_matrix[j][i];
        }
    }
    return rev_adj_matrix;
}

// recursive dfs function for kosaraju
void Graph::fillOrder(int x, vector<bool> & visited, stack<int> & s) {
    visited[x] = true;
    for (int target=0; target<(int)adj_matrix[x].size(); target++) {
        if ((adj_matrix[x][target] > 0 && adj_matrix[x][target] < 11) && !visited[target]) {
            fillOrder(target, visited, s);
        }
    }
    s.push(x);
}

// helper function for kosaraju
void Graph::DFSU(int x, vector<bool> & visited, vector<int> & scc, const vector<vector<int>>& rev_adj_matrix) {
    visited[x] = true;
    scc.push_back(x);
    for (int target=0; target<(int)rev_adj_matrix[x].size(); target++) {
        if ((rev_adj_matrix[x][target] > 0 && rev_adj_matrix[x][target] < 11) && !visited[target]) {
            DFSU(target, visited, scc, rev_adj_matrix);
        }
    }
}

// primary procedure for finding the trustworthiness between src and target.
bool Graph::trust(int src, int target) {
    if (adj_matrix[src][target] > 0 && adj_matrix[src][target] < 11) {
        cout << "There is a direct trustworthy rating between src and target!" << endl;
        return true;
    }
    if (adj_matrix[src][target] > 11) {
        cout << "There is a direct untrustworthy rating between src and target!" << endl;
        return false;
    }
    if (kosaraju(src, target)) {
        cout << "The src and target are in the same strongly connected components where all edges are trustworthy!" << endl;
        return true;
    }
    if (dijkstra(src, target) < 35) {
        cout << "The src and target have a shortest trustworthy path between each other that is less than our threshold of 35!" << endl;
        return true;
    }
    cout << "The src and target shouldn't make a transaction (not trustworthy enough)!" << endl;
    return false;
}