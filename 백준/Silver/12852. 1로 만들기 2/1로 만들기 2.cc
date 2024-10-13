#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int dp[1000001];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i=4;i<=n;i++){
        int min_value = dp[i-1];
        if(i%3 ==0) min_value = min(min_value, dp[i/3]);
        if(i%2 ==0) min_value = min(min_value, dp[i/2]);
        dp[i] = min_value +1;
    }
    
    cout << dp[n] << '\n';
    
    while(n != 1){
        cout << n << " ";
        int index = n-1;
        int min_value = dp[n-1];
        if(n%3 ==0 && min_value > dp[n/3]) {index= n/3;  min_value = dp[n/3];}
        if(n%2 ==0 && min_value > dp[n/2]) {index= n/2;  min_value = dp[n/2];}
        n=index;
    }
    cout << 1 ;
    
    
    return 0;
}