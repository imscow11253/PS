#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321

using namespace std;

int n;
int cost[16][16] = {0,};
int dp[16][1 << 16];

int dfs(int curNode, int status){
    if(status == (1 << n) -1){
        if(cost[curNode][0] == 0) return INF;
        return cost[curNode][0];
    }
    
    if(dp[curNode][status] != -1) return  dp[curNode][status];
    dp[curNode][status] = INF;
     
    for(int i =0;i<n;i++){
        if(cost[curNode][i] ==0) continue;
        if((status & (1 << i)) == (1 << i)) continue;
        dp[curNode][status] = min(dp[curNode][status], cost[curNode][i] + dfs(i, status | 1 << i));
    } 
    return dp[curNode][status];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> cost[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,1);
    
    return 0;
}