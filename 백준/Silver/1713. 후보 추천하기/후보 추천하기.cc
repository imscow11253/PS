#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int n;
int t;
vector<tuple<int, int, int>> vec;

bool compare(tuple<int,int,int> a, tuple<int,int,int> b){
    if(get<1>(a) < get<1>(b)){
        return true;
    }
    if(get<1>(a) == get<1>(b)){
        return get<0>(a) < get<0>(b);
    }
    return false;
}

bool compare2(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> t;
    int candidate;
    int old=0;
    while(t--){
        cin >> candidate;
        sort(vec.begin(),vec.end(),compare);
        int check=0;
        // cout << "==================\n";
        // for(auto a : vec)cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << "\n";
        for(int i=0;i<vec.size();i++){
            auto& a = vec[i];
            if(get<2>(a) == candidate){
                get<1>(a) = get<1>(a)+1;
                check=1;
                break;
            }
        }
        if(check) continue;
        if(vec.size() < n) {vec.push_back(make_tuple(old++, 1, candidate)); continue;}
        vec[0] = make_tuple(old++, 1, candidate);
    }
    sort(vec.begin(), vec.end(),compare2);
    for(auto a : vec){
        cout << get<2>(a) << '\n';
    }
    
    return 0;
}