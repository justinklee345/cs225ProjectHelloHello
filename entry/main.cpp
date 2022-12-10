#include <iostream>
#include "../src/graph.h"

int main() {
    Graph adj_mat("../data/sorted-zero-soc-sign-bitcoinalpha.csv");
    // Graph adj_mat("../data/example.csv");
    // adj_mat.print();
    /*
    Last five transactions
        1201,603,1,1452920400
        280,3449,1,1452920400
        113,7369,-1,1453006800
        3450,97,5,1453438800
        14,3450,1,1453438800
    */
    cout << adj_mat.getRating(1201, 603) << endl; // 1
    cout << adj_mat.getRating(280, 3449) << endl; // 1
    cout << adj_mat.getRating(113, 7369) << endl; // -1
    cout << adj_mat.getRating(3450, 97) << endl; // 5
    cout << adj_mat.getRating(14, 3450) << endl; //1

    // 1(-1) + 11 = 10
    // 1(-1) + 11 = 10
    // -1(-1) + 11 = 12
    // 5(-1) + 11 = 6
    // 1(-1) + 11 = 10
    
    // ratings correctly scaled so that negative ratings have higher weight and greater ratings (5 to 6) have lower weight than lesser ratings (1 to 10)

    vector<int> path = adj_mat.bfs(3450);
    for (auto i : path) {
        cout << i << "->";
    }
    cout << endl;
}