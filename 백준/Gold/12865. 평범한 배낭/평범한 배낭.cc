#include <iostream>

using namespace std;

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    int weight[N+1] ={};
    int value[N+1] ={};
    int DP[N+1][K+1] = {};
    
    for(int i=1;i<=N;i++) cin >> weight[i] >> value[i];
    for(int i =1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(weight[i] <= j) DP[i][j] = max(DP[i-1][j], DP[i-1][j-weight[i]]+value[i]);
            else DP[i][j] = DP[i-1][j];
        }
    }
    cout << DP[N][K];
    return 0;
}