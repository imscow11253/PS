#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int _rank[201];
int parent[201];

int find(int node){
    if(parent[node] == node) return node;
    
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
    for(int i =1;i<=n;i++){
         _rank[i] = 1;
        parent[i] = i;
    }
    
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            bool temp;
            cin >> temp;
            if(temp && find(i) != find(j)){
                _union(i,j);
            }
        }
    }
    
    int prev_parent;
    int check=1;
    for(int i =0;i<m;i++){
        int temp;
        cin >> temp;
        if(i==0) prev_parent = find(temp);
        else{
            if(find(temp) != prev_parent){check = 0; break;}
        }
    }
    
    if(check) cout << "YES";
    else cout << "NO";
    
    return 0;
}