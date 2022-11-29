#include <iostream>
#include "graph.h"

int main() {
    Graph adj_mat("../data/sorted-soc-sign-bitcoinalpha.csv");
    // Graph adj_mat("../data/example.csv");
    // adj_mat.print();
    cout << adj_mat.getRating(15,3451) << endl;
    cout << adj_mat.getRating(3451,98) << endl;
}