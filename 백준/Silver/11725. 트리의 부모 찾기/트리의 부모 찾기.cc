#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> graph[100001];
int parent[100001];
bool visit[100001] = {0,};

void dfs(int node){
    for(int next : graph[node]){
        if(visit[next]) continue;
        visit[next] = true;
        parent[next] = node;
        dfs(next);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int a,b;
    for(int i =1;i<n;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    visit[1] = true;
    dfs(1);
    
    for(int i=2;i<=n;i++) cout << parent[i] << '\n';
    
    return 0;
}