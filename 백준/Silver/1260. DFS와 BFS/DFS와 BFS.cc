#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,r;
vector<int> arr[1001];
int order[1001] ={};
int visit[1001] ={};
int cnt=1;
queue<int> qu;
queue<int> dfs;
queue<int> bfs;

void DFS(int r){
    visit[r] = 1;
    order[r] = cnt++;
    dfs.push(r);
    for(auto a : arr[r]){
        if(!visit[a]){
            DFS(a);
        }
    }
}

void travel(int r){
    qu.pop();
    bfs.push(r);
    
    for(auto a : arr[r]){
        if(!visit[a]){
            visit[a] = 1;
            order[a] =cnt++;
            qu.push(a);   
        }
    }
    
    if(!qu.empty()){
        travel(qu.front());   
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> r;
    
    int a,b;
    
    while(m--){
        cin >> a >> b;
        
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    for(int i =0;i<=n;i++){
        sort(arr[i].begin(), arr[i].end());
    }
    
    visit[r] =1;
    order[r] = cnt++;
    qu.push(r);
    travel(r);
    
    for(int i=0;i<1001;i++){
        visit[i]=0;
    }
    DFS(r);
    
    while(!dfs.empty()){
        cout << dfs.front() << " ";
        dfs.pop();
    }
    cout << '\n';
    while(!bfs.empty()){
        cout <<bfs.front() << " ";
        bfs.pop();
    }
    
    return 0;
}