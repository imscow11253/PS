#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string target = "UNIST";
    vector<long long> dp(6, 0);
    dp[0] = 1; // 시작 상태

    for (int i = 0; i < n; i++) {
        int len = words[i].length();
        vector<long long> next_dp(6, 0);

        for (int j = 0; j <= 5; j++) {
            if (dp[j] == 0) continue;

            for (int k = 0; k <= len; k++) {
                if (j + k <= 5 && words[i].substr(0, k) == target.substr(j, k)) {
                    next_dp[j + k] = (next_dp[j + k] + dp[j]) % MOD;
                }
            }
        }

        dp = next_dp;
    }

    cout << dp[5] << '\n'; // UNIST의 모든 글자를 완성하는 경우의 수

    return 0;
}