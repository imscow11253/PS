#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    vector<pair<int,int>> edges(n);
    unordered_map<int,int> mp;
    
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        edges[i] = {a,b};
        mp[b] = a;
    }
    
    sort(edges.begin(), edges.end());
    
    vector<int> lis;
    vector<int> dp;
    int max_value=0;
    for(auto p : edges){
        auto it = lower_bound(lis.begin(), lis.end(), p.second);
        if(it == lis.end()){
            lis.push_back(p.second);
            dp.push_back(lis.size());
        }
        else{
            *it = p.second;
            dp.push_back((int)(it - lis.begin())+1);
        }
        max_value = max(max_value, (int)lis.size());
    }
    
    // for(int p : dp) cout << p << " ";
    // cout << '\n';
    
    vector<int> result;
    for(int i =n-1;i>=0;i--){
        if(dp[i] == max_value){
            max_value--;
        }
        else{
            result.push_back(edges[i].first);
        }
    }
    
    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for(int p : result) cout << p << '\n';
    
    return 0;
}