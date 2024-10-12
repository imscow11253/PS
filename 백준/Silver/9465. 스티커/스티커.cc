#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;

int t,n;
int score[2][100001];
int dp[3][100001];

int check_dp(){
    dp[0][1] = score[0][1];
    dp[1][1] = score[1][1];
    dp[2][1] = 0;
    for(int j=2;j<=n;j++){
        dp[0][j] = max(max(max(max(dp[0][j-2], dp[1][j-2]), dp[2][j-2]), dp[1][j-1]), dp[2][j-1]) + score[0][j];
        dp[1][j] = max(max(max(max(dp[0][j-2], dp[1][j-2]), dp[2][j-2]), dp[0][j-1]), dp[2][j-1]) + score[1][j];
        dp[2][j] = max(max(max(max(dp[0][j-2], dp[1][j-2]), dp[2][j-2]), dp[1][j-1]), dp[0][j-1]);
    }
    return max(max(dp[0][n], dp[1][n]), dp[2][n]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<3;i++){
            for(int j=0;j<100001;j++){
                dp[i][j] =0;
            }
        }
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++){
                cin >> score[i][j];
            }
        }
        
        cout << check_dp() << '\n';
    }
    
    return 0;
}