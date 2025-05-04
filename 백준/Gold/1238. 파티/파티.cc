#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n,m,x;
vector<pair<int,int>> graph[1001];
bool visit[1001] = {0,};
int result_of_go_to_party[1001];
int result_of_go_back[1001];

void go_to_party(int start_node){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qu; // distance, next_node
    qu.push({0,start_node});
    
    while(!qu.empty()){
        auto a = qu.top();
        qu.pop();
        
        int distance = a.first;
        int node = a.second;
        
        visit[node] = true;
        
        if(node == x){
            result_of_go_to_party[start_node] = distance;
            return ;
        }
        
        for(auto b : graph[node]){
            if(visit[b.first]) continue;
            qu.push({b.second + distance, b.first});
        }
    }
}

void go_back(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qu; // distance, next_node
    qu.push({0,x});
    
    while(!qu.empty()){
        auto a = qu.top();
        qu.pop();
        
        int distance = a.first;
        int node = a.second;
        
        if(visit[node]) continue;
        
        result_of_go_back[node] = distance;
        visit[node] = true;
        
        for(auto b : graph[node]){
            if(visit[b.first]) continue;
            qu.push({b.second + distance, b.first});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> x;
    int sta, en, value;
    for(int i =0;i<m;i++){
        cin >> sta >> en >> value;
        graph[sta].push_back({en, value});
    }
    
    for(int i = 1; i<=n;i++){
        for(int j =0 ;j<=n;j++) visit[j] = false;
        go_to_party(i);   
    }
    
    for(int j =0 ;j<=n;j++) visit[j] = false;
    go_back();
    
    int min_value= -1;
    for(int i =1;i<=n;i++){
        min_value = max(min_value, result_of_go_to_party[i] + result_of_go_back[i]);
    }
    
    cout << min_value;
    
    return 0;
}