#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int memory[101];
int cost[101];
int dp[101][10001]= {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for(int i=1;i<=n;i++) cin >> memory[i];
    for(int i=1;i<=n;i++) cin >> cost[i];
    
    for(int i =1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
			
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    
    // for(int i =1;i<=n;i++){
    //     for(int j=1;j<=15;j++){
    //         cout << dp[i][j] << " ";
    //     }cout << '\n';
    // }
    
    for(int i=0;i<=10000;i++){
        if(dp[n][i] >= m) {cout << i; break;}
    }
    
    return 0;
}