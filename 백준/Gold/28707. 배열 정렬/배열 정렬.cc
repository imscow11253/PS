#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n,m;
int arr[10];
vector<tuple<int,int,int>> oper;
map<vector<int>, vector<pair<vector<int>, int>>> graph; // node, {node, cost} 

void bfs(){
    queue<vector<int>> qu; // next, cost
    set<vector<int>> visited;
    
    vector<int> temp;
    for(int i=0;i<n;i++) temp.push_back(arr[i]);
    qu.push(temp);
    
    while(!qu.empty()){
        auto next = qu.front();
        qu.pop();
        
        if(graph.find(next) != graph.end()) continue;
        if(visited.find(next) != visited.end()) continue;
        else{
            visited.insert(next);
            for(const auto& b : oper){
                auto newNext = next;
                int index1 = get<0>(b)-1;
                int index2 = get<1>(b)-1;
                int weight = get<2>(b);
                
                swap(newNext[index1], newNext[index2]);
                
                graph[next].push_back({newNext, weight});
                
                if(graph.find(newNext) != graph.end()) continue;
                if(visited.find(newNext) != visited.end()) continue;
                qu.push(newNext);
                // cout << next << " to " << newNext << " by " << weight << '\n';
            }
        }
    }
}

int dijkstra(){
    //시작점 node string 구하기
    vector<int> startState;
    for(int i=0;i<n;i++) startState.push_back(arr[i]);
    
    sort(arr, arr+n);
    
    //도착점 node string 구하기
    vector<int> endState;
    for(int i=0;i<n;i++) endState.push_back(arr[i]);
    
    priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq; //cost, next
    set<vector<int>> visit;
    
    pq.push({0, startState});
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        int cost = a.first;
        auto next = a.second;
        
        // cout << next << " " << cost <<'\n';
        
        if(visit.find(next) != visit.end()) continue;
        visit.insert(next);
        bool check = true;
        for(int i =0;i<n;i++){
            if(endState[i] != next[i]) {check = false; break;}
        }
        if(check) return cost;
    
        for(const auto& b : graph[next]){
            // cout << "check : "<<  b.first <<'\n'; 
            if(visit.find(b.first) != visit.end()) continue;
            // cout << "selected : " << b.first << " by " << cost+b.second << '\n';
            pq.push({cost+b.second, b.first});
        }
    }
    
    return -1;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    cin >> m;
    int s,e,c;
    for(int i=0;i<m;i++){
        cin >> s >> e >> c;
        oper.push_back(make_tuple(s,e,c));
    }
    
    //graph 그리기
    bfs();
    
    // for(const auto& a : graph){
    //     cout << a.first << '\n';
    //     for(const auto& b : a.second){
    //         cout << "{" << b.first << ", " << b.second << "} ";
    //     }
    //     cout << '\n';
    // }
    
    cout << dijkstra();
    
    return 0;
}