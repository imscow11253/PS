#include <iostream>
#include <algorithm>

#define NUM 2147483647
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    pair<int,int> arr[N];
    int DP[N][N]={};
    
    int a,b;
    for(int i =0;i<N;i++){
        cin >> a >> b;
        arr[i] = {a,b};
    }
    
    for(int i =1;i<=N;i++){
        for(int j=0;j+i<N;j++){
            DP[j][j+i] = NUM;
            for(int k=j;k<i+j;k++){
                DP[j][j+i] = min(DP[j][j+i], DP[j][k] + DP[k+1][j+i] + (arr[j].first * arr[k].second * arr[j+i].second));
            }
        }
    }
    
    /*for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout << DP[i][j] << " ";
        cout <<'\n';
    }*/
    cout << DP[0][N-1];
    
    return 0;
}