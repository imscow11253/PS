#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int price[3][1000];
int dp[3][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int j=0;j<n;j++){
        for(int i=0;i<3;i++){
            cin >> price[i][j];
        }
    }
    
    int red, green, blue;
    dp[0][1] = INT_MAX;
    dp[1][1] = price[0][0] + price[1][1];
    dp[2][1] = price[0][0] + price[2][1];
    for(int i=2;i<n-1;i++){
        for(int j=0;j<3;j++){
            if(j==0) dp[j][i] = min(dp[1][i-1], dp[2][i-1]) + price[j][i];
            else if(j==1) dp[j][i] = min(dp[0][i-1], dp[2][i-1]) + price[j][i];
            else if(j==2) dp[j][i] = min(dp[1][i-1], dp[0][i-1]) + price[j][i];
        }
    }
    dp[1][n-1] = min(dp[0][n-2], dp[2][n-2]) + price[1][n-1];
    dp[2][n-1] = min(dp[0][n-2], dp[1][n-2]) + price[2][n-1];
    red = min(dp[1][n-1], dp[2][n-1]);
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<n;j++) cout << dp[i][j] << " ";
    //     cout << '\n';
    // }
    
    dp[1][1] = INT_MAX;
    dp[0][1] = price[1][0] + price[0][1];
    dp[2][1] = price[1][0] + price[2][1];
    for(int i=2;i<n-1;i++){
        for(int j=0;j<3;j++){
            if(j==0) dp[j][i] = min(dp[1][i-1], dp[2][i-1]) + price[0][i];
            else if(j==1) dp[j][i] = min(dp[0][i-1], dp[2][i-1]) + price[1][i];
            else if(j==2) dp[j][i] = min(dp[1][i-1], dp[0][i-1]) + price[2][i];
        }
    }
    dp[0][n-1] = min(dp[1][n-2], dp[2][n-2]) + price[0][n-1];
    dp[2][n-1] = min(dp[0][n-2], dp[1][n-2]) + price[2][n-1];
    green = min(dp[0][n-1], dp[2][n-1]);
    
    dp[2][1] = INT_MAX;
    dp[1][1] = price[2][0] + price[1][1];
    dp[0][1] = price[2][0] + price[0][1];
    for(int i=2;i<n-1;i++){
        for(int j=0;j<3;j++){
            if(j==0) dp[j][i] = min(dp[1][i-1], dp[2][i-1]) + price[0][i];
            else if(j==1) dp[j][i] = min(dp[0][i-1], dp[2][i-1]) + price[1][i];
            else if(j==2) dp[j][i] = min(dp[1][i-1], dp[0][i-1]) + price[2][i];
        }
    }
    dp[1][n-1] = min(dp[0][n-2], dp[2][n-2]) + price[1][n-1];
    dp[0][n-1] = min(dp[2][n-2], dp[1][n-2]) + price[0][n-1];
    blue = min(dp[0][n-1], dp[1][n-1]);
    
    // cout << red << " " << green << " " << blue << "\n";
    cout << min(red, min(green, blue));
    
    return 0;
}