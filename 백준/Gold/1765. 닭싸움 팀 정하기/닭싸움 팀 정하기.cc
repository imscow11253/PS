#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int _rank[1001];
int parent[1001];
vector<int> graph[1001];

int find(int node){
    if(node == parent[node]) return node;
    
    parent[node] = find(parent[node]);
    return parent[node];
}

void _union(int node1, int node2){
    int parent1 = find(node1);
    int parent2 = find(node2);
    
    if(_rank[parent1] < _rank[parent2]) swap(parent1, parent2);
    
    parent[parent2] = parent1;
    _rank[parent1] += _rank[parent2];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    char oper; int a,b;
    
    for(int i=1;i<=n;i++){
        _rank[i] = 1;
        parent[i] = i;
    }
    
    while(m--){
        cin >> oper >> a >> b;
        if(oper == 'F'){
            _union(a,b);
        }
        else{
            for(int t : graph[a]){
                _union(t,b);
            }
            graph[a].push_back(b);
            for(int t : graph[b]){
                _union(t,a);
            }
            graph[b].push_back(a);
        }
    }
    
    int result=0;
    for(int i =1;i<=n;i++){
        // cout << parent[i] << " ";
        if(parent[i] == i) result++;
    }
    // cout << '\n';
    
    cout <<result;
    
    return 0;
}