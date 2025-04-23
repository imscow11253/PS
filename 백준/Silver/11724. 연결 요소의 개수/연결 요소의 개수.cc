#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> graph[1001];
bool visit[1001] ={0,};
int result=0;

void bfs(int node){
    queue<int> qu;
    visit[node] = true;
    qu.push(node);
    while(!qu.empty()){
        int target = qu.front();
        qu.pop();
        for(int a : graph[target]){
            if(visit[a]) continue;
            qu.push(a);
            // cout << "From " << target << " Push " << a << '\n';
            visit[a] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i =1;i<=n;i++){
        if(visit[i]) continue;
        bfs(i);
        // for(int j =1;j<=n;j++) cout << visit[j] << " "; cout << '\n';
        result++;
    }
    
    cout << result;
    
    return 0;
}
