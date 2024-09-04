#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubarraySum(const vector<int>& arr) {
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int maxSumRectangle(const vector<vector<int>>& matrix, int n, int m) {
    int maxSum = INT_MIN;

    for (int startRow = 0; startRow < n; startRow++) {
        vector<int> temp(m, 0);

        for (int endRow = startRow; endRow < n; endRow++) {
            for (int i = 0; i < m; i++) {
                temp[i] += matrix[endRow][i];
            }

            int currentMaxSum = maxSubarraySum(temp);
            maxSum = max(maxSum, currentMaxSum);
        }
    }

    return maxSum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = maxSumRectangle(matrix, n, m);
    cout << result << endl;

    return 0;
}