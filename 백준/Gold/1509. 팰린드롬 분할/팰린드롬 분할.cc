#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<bool>> palin(n, vector<bool>(n, false));
    for(int i=0; i<n; ++i) palin[i][i] = true;
    for(int i=0; i+1<n; ++i) palin[i][i+1] = (s[i] == s[i+1]);
    for(int len=3; len<=n; ++len)
        for(int i=0; i+len-1<n; ++i) {
            int j = i+len-1;
            palin[i][j] = (s[i]==s[j] && palin[i+1][j-1]);
        }

    vector<int> dp(n, n+1);
    for (int i=0; i<n; ++i) {
        if (palin[0][i]) dp[i] = 1;
        else for (int j=0; j<i; ++j)
            if (palin[j+1][i])
                dp[i] = min(dp[i], dp[j]+1);
    }
    cout << dp[n-1] << '\n';
}