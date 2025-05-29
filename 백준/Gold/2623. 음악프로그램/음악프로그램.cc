#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<int> graph[1001];
int enterEdge[1001] = {0,};
vector<int> result;

void printDag(){
    queue<int> qu;
    bool visit[1001] = {0,};
    
    for(int i =1;i<=n;i++) if(enterEdge[i] == 0) qu.push({i});

    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        visit[node] = true;
        // cout << node << '\n';
        
        result.push_back(node);
        
        for(int a : graph[node]){
            if(visit[a]) {result.clear(); return;}
            enterEdge[a]--;
            if(enterEdge[a] ==0) qu.push(a);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int num;
    for(int i=0;i<m;i++){
        cin >> num;
        int sta,en;
        if(num ==0) continue;
        if(num ==1) {cin >> sta; continue;}
        cin >> sta;
        num--;
        while(num--){
            cin >> en;
            graph[sta].push_back(en);
            enterEdge[en]++;
            sta = en;
        }
    }
    
    printDag();
    if(result.size() ==0 || result.size() != n)  cout << 0;
    else for(int a : result) cout << a << '\n';
    
    return 0;
}
