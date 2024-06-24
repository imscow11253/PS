#include <iostream>
#include <algorithm>

#define NUM 2000000000
using namespace std;


int cost[501];
int DP[501][501];
int sum[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, K;
    cin >> T;
    while(T--){
        cin >> K;
        
        for(int i =1;i<=K;i++){
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        
        for(int i=1;i<=K;i++){
            for(int j=1;j+i<=K;j++){
                DP[j][j+i] = NUM;
                for(int k=j;k<j+i;k++){
                    DP[j][j+i] = min(DP[j][j+i], DP[j][k] + DP[k+1][j+i] + sum[j+i] - sum[j-1]);
                }
            }
        }
        
        /*for(int i=0;i<=K;i++){
            for(int j=0;j<=K;j++) cout << DP[i][j] << " ";
            cout << '\n';
        }*/
        cout << DP[1][K] << '\n';
    }
    
    return 0;
}