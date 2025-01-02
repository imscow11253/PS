#include <iostream>

using namespace std;

int n;
long long dp[31] ={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    dp[1] = 1; dp[2] = 3;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + (dp[i-2] *2);
    }
    
    // for(int i=1;i<=n;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << '\n';
    if(n ==2) {cout << 3; exit(0);}
    if(n%2 ==0){
        cout << dp[n] - ((dp[n]-dp[n/2]-(dp[n/2-1]*2))/2);
    }
    else{
        cout << dp[n] - ((dp[n]-dp[n/2])/2);
    }
    
    return 0;
}