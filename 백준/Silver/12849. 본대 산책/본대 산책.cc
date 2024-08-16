#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d;
    cin >> d;

    vector<vector<long long>> dp(d + 1, vector<long long>(8, 0));
    dp[0][0] = 1;

    vector<short> arr[8]{
        {1,2},
        {0,2,3},
        {0,1,3,4},
        {1,2,4,5},
        {2,3,5,6},
        {3,4,7},
        {4,7},
        {5,6}
    };

    for (int i = 1; i <= d; i++) {
        for (int j = 0; j < 8; j++) {
            for (auto& neighbor : arr[j]) {
                dp[i][j] = (dp[i][j] + dp[i-1][neighbor]) % MOD;
            }
        }
    }

    cout << dp[d][0] << '\n';

    return 0;
}