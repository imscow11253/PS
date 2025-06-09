#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<int> graph[32001];
int enterNum[32001] = {0,};

void travel(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1;i<=n;i++) if(enterNum[i] == 0) pq.push(i);
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        
        cout << node << " ";
        
        for(int next : graph[node]){
            enterNum[next]--;
            if(enterNum[next] == 0) pq.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int a,b;
    while(m--){
        cin >> a >> b;
        graph[a].push_back(b);
        enterNum[b]++;
    }
    
    travel();
    
    return 0;
}