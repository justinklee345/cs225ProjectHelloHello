#include <catch2/catch_test_macros.hpp>
#include "../src/graph.h"

TEST_CASE("Constructor Test for smaller file", "[weight=5]") {
    Graph testing("constructorTest.csv");
    vector<vector<int>> matrix = testing.getMatrix();
    cout << "Printing Matrix: " << endl;
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.at(i).size(); ++j) {
            cout << matrix[i][j] << "; ";
        }
        cout << endl;
    }
    REQUIRE(matrix[2][1] == 9);
    REQUIRE(matrix[3][0] == 8);
    REQUIRE(matrix[1][3] == 9);
    REQUIRE(matrix[0][2] == 9);
    REQUIRE(true);
}