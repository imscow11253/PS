#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
int candy[30001];
int parent[30001];
int _rank[30001];
int value[30001];

int find(int node){
    if(parent[node] == node) return node;
    
    parent[node] = find(parent[node]);
    return parent[node];
}

void _union(int a, int b){
    int parent_a = find(a);
    int parent_b = find(b);
    
    if(parent_a == parent_b) return;
    
    if(_rank[parent_a] < _rank[parent_b]){
        int temp = parent_a;
        parent_a = parent_b;
        parent_b = temp;
    }
    
    parent[parent_b] = parent_a;
    _rank[parent_a] += _rank[parent_b];
    value[parent_a] += value[parent_b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    for(int i =1;i<=n;i++){
        cin >> candy[i];
        parent[i] = i;
        _rank[i] = 1;
        value[i] = candy[i];
    }
    
    int sta, en;
    while(m--){
        cin >> sta >> en;
        _union(sta, en);
    }
    
    vector<pair<int,int>> vec;
    for(int i =1;i<=n;i++){
        if(parent[i] == i) vec.push_back({_rank[i], value[i]});
    }
    
    int dp[30001][2] = {0,};
    bool check =1;
    for(int j =0;j<vec.size();j++){
        auto a = vec[j];
        int num = a.first;
        int sum_value = a.second;
        
        for(int i =0;i<=k;i++){
            if(check){
                if(i-num <= 0) {dp[i][1] = dp[i][0];}
                else{
                    dp[i][1] = max(dp[i][0], dp[i-num][0] + sum_value);
                }
                // cout << dp[i][1] << " ";   
            }
            else{
                if(i-num <= 0) dp[i][0] = dp[i][1];
                else{
                    dp[i][0] = max(dp[i][1], dp[i-num][1] + sum_value);
                }
                // cout << dp[i][0] << " ";
            }   
        }
        check = !check;
        // cout << '\n';
    }
    
    cout << max(dp[k][0], dp[k][1]);
    
    return 0;
}