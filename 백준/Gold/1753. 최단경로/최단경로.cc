#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int v,e;
int sta;
map<int,int> graph[20001];
int path[20001];
bool visit[20001] = {0,};

void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qu;
    qu.push({0,sta});
    
    while(!qu.empty()){
        auto a = qu.top();
        qu.pop();
        
        int node = a.second;
        int distance = a.first;
        // cout << "selected : " << node << " " << distance << '\n';
        
        if(path[node] >= distance){
            path[node] = min(path[node], distance);
            visit[node] = true;
            
            // cout << "inserted : " ;
            for(pair<int,int> b : graph[node]){
                if(visit[b.first]) continue;
                qu.push({distance + b.second, b.first});
                // cout << b.first << " " << distance + b.second << '\n';
            }   
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e;
    cin >> sta;
    
    int from, to, value;
    for(int i =0;i<e;i++){
        cin >> from >> to >> value;
        if(graph[from].find(to) != graph[from].end()) graph[from][to] = min(value, graph[from][to]);
        else graph[from].insert({to, value});
    }
    
    // for(int i =1;i<=v;i++){
    //     cout << i << " : ";
    //     for(auto a : graph[i]){
    //         cout << a.first << " " << a.second << '\n';
    //     }
    // }
    
    for(int i=1;i<=v;i++) path[i] = INT_MAX;
    dijkstra();
    
    for(int i =1;i<=v;i++){
        if(path[i] == INT_MAX) cout << "INF\n";
        else cout << path[i] << '\n';
    }
    
    return 0;
}