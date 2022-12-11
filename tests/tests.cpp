#include <catch2/catch_test_macros.hpp>
#include "../src/graph.h"

TEST_CASE("Constructor Test (SMALL) normal (randomly selected) test", "[weight=5]") {
    Graph testing("../tests/constructorTest.csv");

    REQUIRE(testing.getRating(3, 2) == 9);
    REQUIRE(testing.getRating(4, 1) == 8);
    REQUIRE(testing.getRating(1, 3) == 8);
}

TEST_CASE("Constructor Test (SMALL) duplicates test", "[weight=5]") {
    Graph testing("../tests/constructorTest.csv");

    // In the case of duplicate ratings (src rates target after two or more separate transactions),
    // we will discard all previous ratings and update our adjacency matrix with most recent rating.
    REQUIRE(testing.getRating(2, 4) == 5);
    REQUIRE(testing.getRating(4, 1) == 8);
}

TEST_CASE("Constructor Test (ACTUAL) normal (randomly selected) test", "[weight=5]") {
    Graph testing("../data/sorted-soc-sign-bitcoinalpha.csv");

    REQUIRE(testing.getRating(15, 3451) == 1);
    REQUIRE(testing.getRating(3451, 98) == 5);
    REQUIRE(testing.getRating(114, 7370) == -1);
}

// TEST_CASE("Constructor Test (ACTUAL) duplicates test", "[weight=5]") {
//     Graph testing("../data/sorted-soc-sign-bitcoinalpha.csv");

//     // In the case of duplicate ratings (src rates target after two or more separate transactions),
//     // we will discard all previous ratings and update our adjacency matrix with most recent rating.
//     REQUIRE(testing.getRating(2, 4) == 5);
//     REQUIRE(testing.getRating(4, 1) == 8);
// }