#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n,m,w;
vector<pair<int,int>> graph[501];
int dist[501];

bool bellman_ford(int sta){
    for(int i =1;i<=n;i++) dist[i] = INT_MAX;
    dist[sta] = 0;
    for(int i =1;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(auto a : graph[j]){
                int node = a.first;
                int value = a.second;
                if(dist[j] == INT_MAX) continue;
                if(dist[node] == INT_MAX || dist[node] > dist[j] + value){
                    dist[node] = dist[j] + value;
                    if(i==n) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> w;
    
        for(int i =1;i<=n;i++) graph[i].clear();
    
        int sta,en,value;
        for(int i=1; i<=n; i++){
            graph[0].push_back({i, 0});
        }
        for(int i =0;i<m;i++){
            cin >> sta >> en >> value;
            graph[sta].push_back({en, value});
            graph[en].push_back({sta, value});
        }
        for(int i =0;i<w;i++){
            cin >> sta >> en >> value;
            graph[sta].push_back({en, value*-1});
        }
        
        if(bellman_ford(1)){
            cout << "YES\n";
        }else cout << "NO\n";
    }
    
    return 0;
}