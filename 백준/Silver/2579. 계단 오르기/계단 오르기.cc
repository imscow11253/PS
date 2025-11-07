#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int step[N];
    for(int i =0;i<N;i++) cin >> step[i];
    
    int DP[N][2];
    DP[0][0] = step[0]; DP[0][1] = step[0];
    DP[1][0] = step[0] + step[1];
    DP[1][1] = step[1];
    for(int i=2;i<N;i++){
        DP[i][0] = DP[i-1][1] + step[i];
        DP[i][1] = step[i];
        DP[i][1] += (DP[i-2][0] > DP[i-2][1]) ? DP[i-2][0] : DP[i-2][1];
    }
    
    if(DP[N-1][0] > DP[N-1][1]) cout << DP[N-1][0];
    else cout << DP[N-1][1];
    
    return 0;
}