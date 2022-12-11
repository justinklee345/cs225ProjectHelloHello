#include <catch2/catch_test_macros.hpp>
#include "../src/graph.h"

TEST_CASE("Constructor Test (SMALL) normal (randomly selected) test", "[weight=5]") {
    Graph testing("../tests/constructorTest.csv", 5);

    REQUIRE(testing.getRating(2, 1) == 2);
    REQUIRE(testing.getRating(3, 0) == 3);
    REQUIRE(testing.getRating(0, 2) == 3);
}

TEST_CASE("Constructor Test (SMALL) duplicates test", "[weight=5]") {
    Graph testing("../tests/constructorTest.csv", 5);

    // In the case of duplicate ratings (src rates target after two or more separate transactions),
    // we will discard all previous ratings and update our adjacency matrix with most recent rating.
    REQUIRE(testing.getRating(1, 3) == 6);
    REQUIRE(testing.getRating(3, 0) == 3);
}

TEST_CASE("Constructor Test (ACTUAL) normal (randomly selected) test", "[weight=5]") {
    Graph testing("../data/sorted-zero-soc-sign-bitcoinalpha.csv", 7604);

    REQUIRE(testing.getRating(14, 3450) == 10);
    REQUIRE(testing.getRating(3450, 97) == 6);
    REQUIRE(testing.getRating(113, 7369) == 12);
}

// This test case isn't necessary because upon inspection of the data, we never get duplicate transaction ratings...
// TEST_CASE("Constructor Test (ACTUAL) duplicates test", "[weight=5]") {
//     Graph testing("../data/sorted-soc-sign-bitcoinalpha.csv");

//     // In the case of duplicate ratings (src rates target after two or more separate transactions),
//     // we will discard all previous ratings and update our adjacency matrix with most recent rating.
//     REQUIRE(testing.getRating(2, 4) == 5);
//     REQUIRE(testing.getRating(4, 1) == 8);
// }

/* Graph Visual
         3
    3 -------> 0

    ^          |
    |          | 3
  6 |          |
    |          V

    1 <------- 2
          2
*/
TEST_CASE("Dijkstra's Algorithm Test (SMALL)", "[weight=5]") {
    Graph testing("../tests/constructorTest.csv", 4);

    REQUIRE(testing.dijkstra(1, 2) == 12);
    REQUIRE(testing.dijkstra(2, 1) == 2);
    REQUIRE(testing.dijkstra(2, 3) == 8);
    REQUIRE(testing.dijkstra(3, 2) == 6);
    REQUIRE(true);
}

/* Graph Visual

         |--------> 5 -------> |
       4 |          ^          | 1
         |        19|          |
         |    2     |    3     V
         4 -------> 3 -------> 0
         |            ^      ^
         |          ^  \    /  |
         |          |   \ _/   | 3
       1 |        6 |   _\     |
         |          |  /   \15 V
         |            /8    \
         | -------> 1 <------- 2
                        2
*/
TEST_CASE("Dijkstra's Algorithm Test (Big)", "[weight=5]") {
    Graph testing("../tests/algorithmTest.csv", 6);

    REQUIRE(testing.dijkstra(1, 2) == 11);
    REQUIRE(testing.dijkstra(2, 1) == 2);
    REQUIRE(testing.dijkstra(2, 3) == 8);
    REQUIRE(testing.dijkstra(3, 2) == 6);
    REQUIRE(testing.dijkstra(1, 0) == 8);
    REQUIRE(testing.dijkstra(3, 5) == 19);
    REQUIRE(testing.dijkstra(5, 1) == 5);
    REQUIRE(testing.dijkstra(4, 0) == 5);
    REQUIRE(testing.dijkstra(4, 5) == 21);

    REQUIRE(true);
}