#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> cities(N);
    for (int i = 0; i < N; ++i) {
        int cost, customer;
        cin >> cost >> customer;
        cities[i] = {cost, customer};
    }

    vector<int> dp(C + 101, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i <= C; ++i) {
        for (const auto& city : cities) {
            int cost = city.first;
            int customer = city.second;
            if (dp[i] != INT_MAX) { 
                dp[i + customer] = min(dp[i + customer], dp[i] + cost);
            }
        }
    }

    int result = INT_MAX;
    for (int i = C; i < dp.size(); ++i) {
        result = min(result, dp[i]);
    }

    cout << result << "\n";
    return 0;
}