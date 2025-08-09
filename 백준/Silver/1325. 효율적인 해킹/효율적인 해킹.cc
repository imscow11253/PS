#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> graph[10001];
bool visit[10001] = {0,};

int bfs(int node){
    queue<int> qu;
    bool _visit[10001] = {0,};
    
    qu.push(node);
    _visit[node] = true;
    
    int result=0;
    
    while(!qu.empty()){
        int next = qu.front();
        qu.pop();
        
        result++;
        visit[next] = true;
        
        for(int a : graph[next]){
            if(_visit[a]) continue;
            _visit[a] = true;
            qu.push(a);
        }
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    int a,b;
    while(m--){
        cin >> a >> b;
        graph[b].push_back(a);
    }
    
    vector<pair<int,int>> vec;
    for(int i =1;i<=n;i++){
        // if(visit[i]) continue;
        int result = bfs(i);
        vec.push_back({result, i});
    }
    
    sort(vec.begin(), vec.end(), greater());
    
    int result =vec[0].first;
    vector<int> vec2;
    for(const auto& p : vec){
        if(p.first < result) break;
        vec2.push_back(p.second);
    }
    
    for(int i = vec2.size()-1; i>=0;i--){
        cout << vec2[i] << " ";
    }
    
    return 0;
}