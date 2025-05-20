#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int n,m;
int enter[32001] {0,};
vector<int> graph[32001];

void dag(){
    queue<int> qu;
    for(int i =1;i<=n;i++) if(enter[i] ==0) qu.push(i);
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        
        cout << node << " ";
        for(int a : graph[node]){
            enter[a]--;
            if(enter[a] ==0) qu.push(a);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >>  n >> m;
    int a,b;
    for(int i =0;i<m;i++){
        cin >> a >> b;
        enter[b] += 1;
        graph[a].push_back(b);
    }
    
    dag();
    
    return 0;
}