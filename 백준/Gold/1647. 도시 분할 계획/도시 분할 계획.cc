#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<pair<int,int>> graph[100001];
bool visit[100001]={0,};
vector<int> result;

void prim(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // value, next
    pq.push({0, start});

    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        int value = a.first;
        int node = a.second;
        
        // cout << node << "\n";
        
        if(visit[node]) continue;
        
        visit[node] = true;
        result.push_back(value);
        
        for(auto b : graph[node]){
            if(visit[b.first]) continue;
            pq.push({b.second, b.first});
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int sta, en, value;
    for(int i =0;i<m;i++){
        cin >> sta >> en >> value;
        graph[sta].push_back({en, value});
        graph[en].push_back({sta, value});
    }
    
    prim(1);
    
    int max_value=0;
    int sum=0;
    for(int a : result){
        max_value = max(max_value, a);
        sum += a;
    }
    
    cout << sum - max_value;
    
    return 0;
}