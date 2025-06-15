#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[300][300];
int dp[300][300] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >>m;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j] == 1) dp[i][j] = 1;
            if( i-1 >=0 && j-1>=0) dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
            else if(i-1 >=0) dp[i][j] += dp[i-1][j];
            else dp[i][j] += dp[i][j-1];
            // cout << dp[i][j] << " ";
        }
        // cout << '\n';
    }
    
    cout << dp[n-1][m-1];
    
    return 0;
}