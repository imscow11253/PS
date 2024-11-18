#include <iostream>

using namespace std;

int n,m,k;
int dp[102][102] = {0,};

void fill_dp(){
    for(int i =1;i<=n;i++) dp[i][0] = 1;
    for(int i =1;i<=m;i++) dp[0][i] = 1;
    
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
            // cout << dp[i][j] << " ";
        }
        // cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >>m >> k;
    fill_dp();
    
    if(dp[n][m] < k) {cout << -1; return 0;}
    
    int row =n, col = m;
    while(row >0 && col >0){
        // cout <<dp[row-1][col] << " " << k << " " << row << " " << col<< "\n";
        if(dp[row-1][col] >= k){
            row--;
            cout << "a";
        }
        else{
            k -= dp[row-1][col];
            col--;
            cout << "z";
        }
    }
    
    if(row ==0){
        while(col--)cout << "z";
    }
    else while(row--) cout << "a";
    
    return 0;
}