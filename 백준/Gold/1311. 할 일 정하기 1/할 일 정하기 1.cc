#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int n;
int arr[21][21];
int dp[1<<20];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> arr[i][j];

    for(int i=0;i<(1<<n);i++) dp[i]=INT_MAX;
    dp[0]=0;

    for(int mask=0; mask<(1<<n); mask++){
        int cnt = __builtin_popcount(mask);
        for(int j=0;j<n;j++){
            if(!(mask&(1<<j))){
                dp[mask | (1<<j)] = min(dp[mask | (1<<j)], dp[mask]+arr[cnt+1][j+1]);
            }
        }
    }
    cout<<dp[(1<<n)-1];
    return 0;
}