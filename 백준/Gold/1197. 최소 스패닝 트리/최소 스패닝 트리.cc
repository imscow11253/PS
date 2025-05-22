#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int v,e;
vector<pair<int,int>> graph[10001];
int result=0;
bool visit[10001] = {0,};

void prim(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //value, node 
    // priority_queue<pair<int,int>> pq; //value, node 
    for(auto a : graph[1]){
        pq.push({a.second, a.first});
    }
    visit[1] = true;
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        int value = a.first;
        int node = a.second;
        // cout << node << " " << value << '\n';
        
        if(visit[node]) continue;
        else visit[node]=true;
        result += value;
        
        for(auto b : graph[node]){
            if(!visit[b.first]) {
                pq.push({b.second, b.first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e;
    int sta, en, value;
    for(int i =0;i<e;i++){
        cin >> sta >> en >> value;
        graph[sta].push_back({en,value});
        graph[en].push_back({sta, value});
    }
    
    prim();
    cout << result;
    
    return 0;
}