#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

int n,m;
map<int,int> graph[100001];
vector<pair<int,int>> mst[100001];
int start, target;

void prim(){
    priority_queue<tuple<int,int,int>> pq; //vlaue, sta, en
    bool visit[100001] = {0,};
    for(auto a : graph[start]){
        pq.push(make_tuple(a.second, start, a.first));
    }
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        int sta = get<1>(a);
        int en = get<2>(a);
        int value = get<0>(a);
        
        if(visit[en]) continue;
        
        visit[en] = true;
        mst[sta].push_back({en, value});
        mst[en].push_back({sta, value});
        
        for(auto b : graph[en]){
            if(!visit[b.first]) pq.push(make_tuple(b.second, en, b.first));
        }
    }
}

int bfs(){
    queue<pair<int,int>> qu;
    bool visit[100001] = {0,};
    
    qu.push({start, INT_MAX});
    visit[start] = true;
    
    int result = INT_MAX;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int next = a.first;
        int value = a.second;
        
        visit[next] = true;
        if(next == target) return value;
        
        for(auto b : mst[next]){
            if(!visit[b.first]) qu.push({b.first, min(b.second, value)});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int sta, en, value;
    while(m--){
        cin >> sta >> en >> value;
        if(graph[sta].find(en) != graph[sta].end()){
            graph[sta][en] = max(value, graph[sta][en]);
            graph[en][sta] = max(value, graph[en][sta]);
        }
        else{
            graph[sta].insert({en, value});
            graph[en].insert({sta, value});
        }
    }
    
    cin >> start >> target;
    
    prim();
    cout << bfs();
    
    return 0;
}