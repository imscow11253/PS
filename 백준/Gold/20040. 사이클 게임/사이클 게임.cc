#include <iostream>

using namespace std;

int n,m;
int parent[500000];
int _rank[500000];

int find(int node){
    if(parent[node] == node) return node;
    parent[node] = find(parent[node]);
    return parent[node];
}

void _union(int a, int b){
    int a_parent = find(a);
    int b_parent = find(b);
    
    if(_rank[a_parent] < _rank[b_parent]){
        int temp = a_parent;
        a_parent = b_parent;
        b_parent = temp;
    }
    
    parent[b_parent] = a_parent;
    _rank[b_parent] += _rank[a_parent];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i =0;i<500000;i++) {
        parent[i] = i;
        _rank[i] = 1;
    }
    
    int sta, en;
    for(int i=1;i<=m;i++){
        cin >> sta >> en;
        if(find(sta) == find(en)){
            cout << i << '\n';
            exit(0);
        }
        _union(sta, en);
    }
    
    cout << 0 << '\n';
    
    return 0;
}