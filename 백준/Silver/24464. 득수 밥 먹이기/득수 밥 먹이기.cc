#include <iostream>

using namespace std;

int n;
long long dp[5][200001] ={0,};
long long divide = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0;i<5;i++) dp[i][1] =1;
    
    for(int i=2;i<=n;i++){
        dp[0][i] = (dp[1][i-1] + dp[2][i-1] + dp[3][i-1] + dp[4][i-1]) % divide;
        dp[1][i] = (dp[0][i-1] + dp[3][i-1] + dp[4][i-1]) % divide;
        dp[2][i] = (dp[0][i-1] + dp[4][i-1]) % divide;
        dp[3][i] = (dp[0][i-1] + dp[1][i-1]) % divide;
        dp[4][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) % divide;
    }
    
    cout << (dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n]) % divide;
    
    return 0;
}