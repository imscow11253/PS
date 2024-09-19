#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>
#include <stdlib.h>

using namespace std;

int n;
vector<int> vec;

bool compare(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int temp;
    int n_temp = n;
    while(n_temp--){
        cin >> temp;
        vec.push_back(temp);
    }
    
    vector<tuple<int,int,int>> snowman;
    for(int i=0;i<vec.size()-1;i++){
        for(int j=i+1;j<vec.size();j++){
            snowman.push_back(make_tuple(i,j,vec[i]+vec[j]));
        }
    }
    
    sort(snowman.begin(), snowman.end(), compare);
    
    int result = INT_MAX;
    for(int i =0;i<snowman.size()-1;i++){
        for(int j=i+1;j<snowman.size();j++){
            if(get<0>(snowman[i]) != get<0>(snowman[j]) && get<0>(snowman[i]) != get<1>(snowman[j]) && get<1>(snowman[i]) != get<0>(snowman[j]) && get<1>(snowman[i]) != get<1>(snowman[j])){
                result = min(result, get<2>(snowman[j]) - get<2>(snowman[i]));
                break;
            }
        }
    }
    
    cout <<result;

    return 0;
}