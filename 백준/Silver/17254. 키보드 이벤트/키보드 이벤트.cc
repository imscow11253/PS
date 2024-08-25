#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n,m;
vector<tuple<int,int,char>> vec;

bool compare(tuple<int,int,char> a, tuple<int,int,char> b){
    int a_first = get<0>(a);
    int a_second = get<1>(a);
    int b_first = get<0>(b);
    int b_second = get<1>(b);
    
    if(a_second == b_second){
        return a_first < b_first;
    }
    else return a_second < b_second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    int a,b;
    char temp;
    while(m--){
        cin >> a >> b >> temp;
        vec.push_back(make_tuple(a,b,temp));
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    for(auto a : vec){
        cout << get<2>(a);
    }
    
    return 0;
}