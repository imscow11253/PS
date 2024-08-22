#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<tuple<int,int,int>> vec;
vector<tuple<int,int,int>> result;

bool compare(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<0>(a) < get<0>(b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    int a,b,c;
    int n_temp = n;
    while(n--){
        cin >> a >> b >> c;
        vec.push_back(make_tuple(a,b,c));
    }
    
    sort(vec.begin(), vec.end(), compare);
    // cout << "===================\n";
    // for(auto a : vec){
    //     cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << '\n';
    // }
    
    for(int i =0;i<n_temp;i++){
        if(get<2>(vec[i]) == 0) continue;
        result.push_back(vec[i]);
        for(int j=i;j<n_temp;j++){
            if(get<0>(vec[j]) <= get<1>(result.back())){
                if(get<2>(result.back()) > get<2>(vec[j])) get<2>(result.back()) = get<2>(vec[j]);
                if(get<1>(result.back()) < get<1>(vec[j])) get<1>(result.back()) = get<1>(vec[j]);
                get<2>(vec[j]) =0;
            }
            else break;
            // cout << "===================\n";
            // for(auto a : result){
            //     cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << '\n';
            // }
        }
    }
    
    cout << result.size() << '\n';
    for(auto a : result){
        cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << '\n';
    }
    
    return 0;
}