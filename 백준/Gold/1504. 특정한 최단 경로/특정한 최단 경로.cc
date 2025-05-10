#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int n,e;
map<int,int> graph[801]; 
int v1,v2;
int distance_of_node_to_start;
int distance_of_node_to_end;
int distance_of_node_to_via;

void dijkstra(int start_node, int via){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // distance, next_node
    bool visit[801] = {0,};
    
    distance_of_node_to_start = INT_MAX;
    distance_of_node_to_end = INT_MAX;
    distance_of_node_to_via = INT_MAX;
    
    // cout << start_node << " : \n";
    
    pq.push({0,start_node});
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        int distance = a.first;
        int node = a.second;
        
        visit[node] = true;
        
        // cout << node << " " << distance << '\n';
        
        if(node == 1) distance_of_node_to_start = min(distance, distance_of_node_to_start);
        if(node == n) distance_of_node_to_end = min(distance, distance_of_node_to_end);
        if(node == via) distance_of_node_to_via = min(distance_of_node_to_via, distance);

        if(distance_of_node_to_start != INT_MAX && 
            distance_of_node_to_end != INT_MAX &&
            distance_of_node_to_via != INT_MAX
        ) return;
        // cout << "push : ";
        for(auto b : graph[node]){
            if(visit[b.first]) continue;
            pq.push({distance + b.second, b.first});
            // cout << "{" << distance + b.second << ", " << b.first << "}, ";
        }
        // cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> e;
    int sta,en,value;
    for(int i =0;i<e;i++){
        cin >> sta >> en >> value;
        if(graph[sta].find(en) != graph[sta].end()){
            graph[sta][en] = min(value, graph[sta][en]);
            graph[en][sta] = min(value, graph[en][sta]);
        }
        else{
            graph[sta].insert({en, value});
            graph[en].insert({sta, value});
        }
    }
    
    cin >> v1 >> v2;
    
    dijkstra(v1, v2);
    
    int v1_to_start = distance_of_node_to_start;
    int v1_to_end = distance_of_node_to_end;
    
    if(v1_to_start == INT_MAX || v1_to_end == INT_MAX){
        cout << -1;
        return 0;
    }
    
    dijkstra(v2,v1);
    
    int v2_to_start = distance_of_node_to_start;
    int v2_to_end = distance_of_node_to_end;
    
    if(v2_to_start == INT_MAX || v2_to_end == INT_MAX || distance_of_node_to_via == INT_MAX){
        cout << -1;
        return 0;
    }
    
    // cout << v1_to_start << " " << v1_to_end << '\n';
    // cout << v2_to_start << " " << v2_to_end << '\n';
    // cout << distance_of_node_to_via << '\n';
    cout << min(v1_to_start + v2_to_end + distance_of_node_to_via, v1_to_end + v2_to_start + distance_of_node_to_via);
    
    return 0;
}