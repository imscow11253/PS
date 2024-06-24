#include <iostream>
#include <algorithm>

#define NUM 2147483647
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    int value[N+1];
    for(int i =1;i<=N;i++){
        cin >> value[i];
    }
    
    int DP[K+1] = {1};
    for(int i =1;i<=N;i++){
        for(int j=value[i]; j<=K;j++){
            DP[j] += DP[j-value[i]];
        }
       /* for(int a : DP) cout << a << " ";
        cout << '\n';*/
    }
    cout << DP[K];
    return 0;
}