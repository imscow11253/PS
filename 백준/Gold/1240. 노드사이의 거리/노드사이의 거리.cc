#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<pair<int,int>> graph[1001];

int bfs(int sta, int en){
    queue<pair<int,int>> qu;
    qu.push({sta, 0});
    
    bool visit[1001] = {0,};
    visit[sta] = true;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int node = a.first;
        int distance = a.second;
        
        if(node == en){
            return distance;
        }
        
        for(const auto& b : graph[node]){
            if(!visit[b.first]){
                visit[b.first] = true;
                qu.push({b.first, distance + b.second});
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int sta, en, weight;
    for(int i=0;i<n-1;i++){
        cin >> sta >> en >> weight;
        graph[sta].push_back({en, weight});
        graph[en].push_back({sta, weight});
    }
    
    while(m--){
        cin >> sta >> en;
        cout << bfs(sta, en) << '\n';
    }
    
    return 0;
}