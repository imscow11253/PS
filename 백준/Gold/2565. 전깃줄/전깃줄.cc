#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getBigger(int a, int b){
    if(a>b) return a;
    return b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<pair<int,int>> vec;
    int N, max;
    cin >> N;
    
    for(int i =0;i<N;i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a,b});
    }
    sort(vec.begin(), vec.end());
    
    int result=0;
    int DP[N]={}; DP[0] =1;
    for(int i=1; i<N;i++){
        max =0;
        for(int j=0;j<i;j++){
            if(vec[i].second > vec[j].second){
                if(DP[j] >= max) {DP[i] = DP[j] +1; max=DP[i];}
            }
        }
        if(DP[i] == 0) DP[i] = 1;
        result = getBigger(result,DP[i]);
    }
    cout << N-result;
   
    return 0;
}