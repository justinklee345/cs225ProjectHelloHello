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

    cout << "dist: " << adj_mat.dijkstra(3450, 2665) << endl;
    cout << "dist: " << adj_mat.dijkstra(3450, 1944) << endl;
    cout << "dist: " << adj_mat.dijkstra(3450, 807) << endl;
    cout << "dist: " << adj_mat.dijkstra(3450, 1849) << endl;
    cout << "dist: " << adj_mat.dijkstra(3450, 1014) << endl;

    // returns rating immediately if there is already rating between users
    // otherwise returns distance between users, with shorter distances representing more trustworthy transcation paths
    // a large number could also represent longer transaction paths, but we assume the longer the transaction path, the reliablity falls.
    cout << "trust: " << adj_mat.trust(3450, 2665) << endl; // 61 since dijkstra runs
    cout << "trust: " << adj_mat.trust(3450, 97) << endl; // 6 since rating already exists between two users

}