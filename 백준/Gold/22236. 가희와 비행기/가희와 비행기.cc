#include <iostream>

using namespace std;

int d,m;
long long dp[4002][4002] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> d >>m;
    if(d==2) {cout << 1; return 0;}
    dp[1][1]=1;
    
    for(int j=2;j<=d;j++){
        for(int i =1;i<=4000;i++){
            dp[i][j] = (dp[i-1][j-1] + dp[i+1][j-1])%m;
        }
    }
    
    // for(int i =0;i<=5;i++){
    //     for(int j=0;j<=d;j++){
    //         cout << dp[i][j] << " ";
    //     }cout << '\n';
    // }
    
    cout << dp[1][d-1];
    
    return 0;
}