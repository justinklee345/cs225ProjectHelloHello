#include <iostream>
#include "../src/graph.h"

int main() {
    Graph bitcoinRatings("../data/sorted-zero-soc-sign-bitcoinalpha.csv", 7604);

    bool val = bitcoinRatings.trust(1201, 603);
    cout << "Is there trust between User 1201 and User 603? ";
    if (val) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << endl;

    val = bitcoinRatings.trust(1761, 1461);
    cout << "Is there trust between User 1761 and User 1461? ";
    if (val) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << endl;

    int dijkstra_method = bitcoinRatings.dijkstra(3450, 807);
    cout << "Is there trust between User 3450 and User 807? (dijkstra's method) ";
    if (dijkstra_method < 35) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << endl;

    val = bitcoinRatings.trust(3058, 2944);
    cout << "Is there trust between User 3058 and User 2944? ";
    if (val) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << endl;
}