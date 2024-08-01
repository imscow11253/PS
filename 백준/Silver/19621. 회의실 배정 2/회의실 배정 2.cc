#include <iostream>

using namespace std;

int n;
int arr[26] ={};
int start[26] = {};
int last[26] = {};
int num[26] = {};
int dp[26] = {};
int dp1[26] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int sta, en, peo;
    for(int i=1;i<=n;i++){
        cin >> sta >> en >> peo;
        start[i]=sta;
        last[i] = en;
        num[i] = peo;
    }
    
    dp[1] = num[1];
    dp1[1] = 0;
    
    for(int i=2;i<=n;i++){
        // for(auto a : dp) cout << a << " ";
        // cout << '\n';
        // for(auto a : dp1) cout << a << " ";
        // cout << '\n';
        dp[i] = dp1[i-1] + num[i];
        dp1[i] = (dp[i-1] > dp1[i-1]) ? dp[i-1] : dp1[i-1];
    }
    
    if(dp[n] > dp1[n]) cout << dp[n];
    else cout << dp1[n];
    
    return 0;
}