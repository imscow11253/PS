#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int DP[n+1]={};
    DP[1] = 0;
    DP[2] = 1;
    DP[3] = 1;
    
    for(int i=1;i<=n;i++){
        if(i+1 <= n && (DP[i+1]==0 || DP[i+1] > DP[i]+1)) DP[i+1] = DP[i]+1;
        if(i*2 <= n && (DP[i*2]==0 || DP[i*2] > DP[i]+1)) DP[i*2] = DP[i]+1;
        if(i*3 <= n && (DP[i*3]==0 || DP[i*3] > DP[i]+1)) DP[i*3] = DP[i]+1;
    }
    
    // for(int a : DP){
    //     cout << a << " ";
    // }
    // cout << '\n';
    cout << DP[n];
    
    return 0;
}