#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n,m;
vector<int> graph[101];

bool visit[101];

int bfs(int from, int to){
    for(int i =1;i<=n;i++) visit[i] = false;
    queue<pair<int,int>> qu;
    qu.push({from,0});
    visit[from] = true;
    // cout << from << ": ";
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int node = a.first;
        int distance = a.second;
        
        // cout << node << " " ;
        
        if(node == to) {
            // cout << "(" << distance << ")\n";
            return distance;
        }
        
        for(int next : graph[node]){
            if(visit[next]) continue;
            qu.push({next, distance+1});
            visit[next] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int a,b;
    for(int i =0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int result = INT_MAX;
    int person;
    for(int i =1;i<=n;i++){
        int sum =0;
        for(int j =1;j<=n;j++){
            if(i==j) continue;
            sum += bfs(i,j);
        }
        if(result > sum){
            result = sum;
            person = i;
        }
    }
    
    cout << person;
    
    return 0;
}