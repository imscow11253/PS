#include <iostream>

using namespace std;

int dp[12];

void fill_dp(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4;i<12;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    fill_dp();
    
    int a;
    while(t--){
        cin >> a;
        cout << dp[a] << '\n';
    }
    
    return 0;
}