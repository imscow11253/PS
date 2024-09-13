#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<long long> st;
vector<pair<long long,int>> vec;

bool compare(pair<long long,int> a, pair<long long,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long temp;
    while(n--){
        cin >> temp;
        if(st.find(temp) != st.end()){
            for(auto &a : vec){
                if(a.first == temp) {
                    a.second++;
                    break;
                }
            }
        }
        else{
            st.insert(temp);
            vec.push_back({temp, 1});
        }
    }
    
    sort(vec.begin(), vec.end(), compare);
    
    cout << vec[0].first;
    
    return 0;
}