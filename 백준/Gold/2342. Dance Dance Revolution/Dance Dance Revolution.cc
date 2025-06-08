#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int cost[5][5] = {
    {0,2,2,2,2},
    {2,1,3,4,3},
    {2,3,1,3,4},
    {2,4,3,1,3},
    {2,3,4,3,1}
};

int dp[100001][5][5]; // step, 왼발위치, 오른발위치
vector<int> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    while (cin >> x, x != 0) vec.push_back(x);

    fill(&dp[0][0][0], &dp[0][0][0]+100001*5*5, INT_MAX);
    dp[0][0][0] = 0;

    for (int i = 0; i < vec.size(); i++) {
        int nxt = vec[i];
        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                if (dp[i][l][r] == INT_MAX) continue;
                // 왼발 이동
                if (nxt != r) // 왼발이 현재 오른발 위치와 같지 않게
                    dp[i+1][nxt][r] = min(dp[i+1][nxt][r], dp[i][l][r] + cost[l][nxt]);
                // 오른발 이동
                if (nxt != l)
                    dp[i+1][l][nxt] = min(dp[i+1][l][nxt], dp[i][l][r] + cost[r][nxt]);
            }
        }
    }

    int ans = INT_MAX;
    for (int l = 0; l < 5; l++) for (int r = 0; r < 5; r++)
        ans = min(ans, dp[vec.size()][l][r]);
    cout << ans << '\n';

    return 0;
}