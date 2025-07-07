#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>

using namespace std;

int n;
vector<pair<int,long long>> edges[100000];
long long result =0;

void prim(){
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq; //cost, next
    bool visit[100000] = {0,};
    
    pq.push({0,0});
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        long long cost = a.first;
        int next = a.second;
        
        // cout << next  << " "  << cost << '\n';
        
        if(visit[next]) continue;
        
        result += cost;
        visit[next] = true;
        
        for(const auto& n : edges[next]){
            if(!visit[n.first]) pq.push({n.second, n.first});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    vector<pair<long long,int>> x_vec;
    vector<pair<long long,int>> y_vec;
    vector<pair<long long,int>> z_vec;
    long long a,b,c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        x_vec.push_back({a,i});
        y_vec.push_back({b,i});
        z_vec.push_back({c,i});
    }
    sort(x_vec.begin(), x_vec.end());
    sort(y_vec.begin(), y_vec.end());
    sort(z_vec.begin(), z_vec.end());
    
    for(int i=0;i<n-1;i++){
        edges[x_vec[i].second].push_back({x_vec[i+1].second, fabs(x_vec[i].first - x_vec[i+1].first)});
        edges[x_vec[i+1].second].push_back({x_vec[i].second, fabs(x_vec[i].first - x_vec[i+1].first)});
        edges[y_vec[i].second].push_back({y_vec[i+1].second, fabs(y_vec[i].first - y_vec[i+1].first)});
        edges[y_vec[i+1].second].push_back({y_vec[i].second, fabs(y_vec[i].first - y_vec[i+1].first)});
        edges[z_vec[i].second].push_back({z_vec[i+1].second, fabs(z_vec[i].first - z_vec[i+1].first)});
        edges[z_vec[i+1].second].push_back({z_vec[i].second, fabs(z_vec[i].first - z_vec[i+1].first)});
    }
    
    prim();
    cout << result;
    
    return 0;
}