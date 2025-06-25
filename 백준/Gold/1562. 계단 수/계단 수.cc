#include <iostream>
#include <cstring>

using namespace std;

int n;
long long dp[101][1 << 10][10]; // 자리, 숫자 mask, 마지막 숫자

long long dfs(int pos, int status, int prev) {
    if (pos == n-1) {
        return (status == (1<<10)-1) ? 1 : 0;
    }
    long long& res = dp[pos][status][prev];
    if (res != -1) return res;
    res = 0;
    if (prev > 0)
        res += dfs(pos+1, status | (1<<(prev-1)), prev-1);
    if (prev < 9)
        res += dfs(pos+1, status | (1<<(prev+1)), prev+1);
    res %= 1000000000;
    return res;
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    long long answer = 0;
    for (int i = 1; i <= 9; i++) {
        answer += dfs(0, 1<<i, i);
        answer %= 1000000000;
    }
    cout << answer << endl;
    return 0;
}