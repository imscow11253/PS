#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
long long dp[101][101][101] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    long long a,b,c;
    
    for(int k=0;k<=100;k++){
        for(int i =0;i<=100;i++){
            for(int j =0;j<=100;j++){
                if(k ==0 && i == j) dp[k][i][j] =0;
                else dp[k][i][j] = LLONG_MAX;
            }
        }
    }
    
    while(m--){
        cin >> a >> b >> c;
        if(dp[0][a][b] == LLONG_MAX) dp[0][a][b] = c;
        else dp[0][a][b] = min(dp[0][a][b], c);
    }
    
    for(int k=1;k<=n;k++){
        for(int i =1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(dp[k-1][i][k] != LLONG_MAX && dp[k-1][k][j] != LLONG_MAX)
                    dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);
                else
                    dp[k][i][j] = dp[k-1][i][j];
            }
        }
    }
    
    // for(int i =1;i<=n;i++){
    //     for(int j =1;j<=n;j++){
    //         cout << dp[1][i][j] << " ";
    //     }cout << '\n';
    // }
    
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(dp[n][i][j] == LLONG_MAX) cout << 0 << " ";
            else cout << dp[n][i][j] << " ";
        }cout << '\n';
    }
    
    return 0;
}