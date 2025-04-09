#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> triangle = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}
    };

    // Start from the second last row and move upwards
    for (int row = triangle.size() - 2; row >= 0; row--) {
        for (int col = 0; col < triangle[row].size(); col++) {
            triangle[row][col] += max(triangle[row + 1][col], triangle[row + 1][col + 1]);
        }
    }

    cout << "Maximum path sum is: " << triangle[0][0] << endl;

    return 0;
}
