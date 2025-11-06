#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int DP[N][3];
    
    cin >> DP[0][0] >> DP [0][1] >> DP[0][2];
 
    for(int i =1;i<N;i++){
        cin >> DP[i][0] >> DP[i][1] >> DP[i][2];
        DP[i][0] += (DP[i-1][1] > DP[i-1][2]) ? DP[i-1][2] : DP[i-1][1];
        DP[i][1] += (DP[i-1][0] > DP[i-1][2]) ? DP[i-1][2] : DP[i-1][0];
        DP[i][2] += (DP[i-1][1] > DP[i-1][0]) ? DP[i-1][0] : DP[i-1][1];
    }
  
    int min = (DP[N-1][0] > DP[N-1][1]) ? DP[N-1][1] : DP[N-1][0];
    min = (min > DP[N-1][2]) ? DP[N-1][2] : min;
    
    cout << min;
    
    return 0;
}