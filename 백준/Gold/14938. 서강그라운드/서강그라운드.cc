#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int n,m,r;
int items[101];
vector<pair<int,int>> graph[101];
bool visit[101];

int dijkstra(int start){
    memset(visit, false, sizeof(visit));
    int min_distance[101];
    for(int i =1;i<=n;i++) min_distance[i] = INT_MAX;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // distance, node
    pq.push({0,start});
    
    // cout << start << " : \n";
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        int distance = a.first;
        int node = a.second;
        
        // cout << node  << " " << distance << '\n';
        
        if(visit[node]) continue;
        visit[node] = true;
        min_distance[node] = min(min_distance[node], distance);
        
        for(auto p : graph[node]){
            if(!visit[p.first]) pq.push({distance + p.second, p.first});
        }
    }
    
    int result=0;
    for(int i =1;i<=n;i++){
        if(i == start) {result += items[i]; continue;}
        if(min_distance[i] <= m) result += items[i];
        // cout << min_distance[i] << " ";
    }
    // cout << '\n';
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> r;
    for(int i =1;i<=n;i++){
        cin >> items[i];
    }
    int sta,en,value;
    for(int i =0;i<r;i++){
        cin >> sta >> en >> value;
        graph[sta].push_back({en, value});
        graph[en].push_back({sta, value});
    }
    
    int max_value =0;
    for(int i =1;i<=n;i++){
        max_value = max(max_value, dijkstra(i));
    }
    
    cout << max_value;
    
    return 0;
}