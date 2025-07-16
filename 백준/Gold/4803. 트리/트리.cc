#include <iostream>
#include <vector>

using namespace std;

bool dfs(int prev, int node, vector<vector<int>> &graph, vector<bool> &visit){
    // cout << node << " " ;
    visit[node] = true;
    for(const int &next : graph[node]){
        if(next == prev) continue;
        if(visit[next]) return false;
        if(! dfs(node, next, graph, visit)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n=1,m=1;
    int index =1;
    while(n != 0 || m != 0){
        cin >> n >> m;
        if(n ==0 && m== 0) break;
        vector<vector<int>> graph(n+1);
        vector<bool> visit(n+1, false);
        
        int sta, en;
        for(int i =0;i<m;i++){
            cin >> sta >> en;
            if(sta == en) continue;
            graph[sta].push_back(en);
            graph[en].push_back(sta);
        }
        
        int tree=0;
        for(int i =1;i<=n;i++){
            if(visit[i]) continue;
            // cout << '\n';
            if(dfs(0, i, graph, visit)){
                tree++;
            }
        }
        
        cout << "Case " << index << ": ";
        if(tree ==0 ) cout << "No trees.\n";
        else if(tree ==1) cout << "There is one tree.\n";
        else cout << "A forest of " << tree << " trees.\n";
        index++;
    }
    
    return 0;
}