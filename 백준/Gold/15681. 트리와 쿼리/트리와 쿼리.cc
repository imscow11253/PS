#include <iostream>
#include <vector>

using namespace std;

int n,r,q;
vector<int> graph[100001];
int subNode[100001];
bool visit[100001] ={0,};

int dfs(int node){
    int result =1;
    visit[node] = true;
    for(int child : graph[node]){
        if(!visit[child]) result += dfs(child);
    }
    subNode[node] = result;
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> r >> q;
    int a,b;
    for(int i =0;i<n-1;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(r);
    
    int query;
    while(q--){
        cin >> query;
        cout << subNode[query] << '\n';
    }
    
    return 0;
}