#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,k;
int parent[4000000];

int find(int node){
    if(parent[node] == node) return node;
    
    parent[node] = find(parent[node]);
    return parent[node];
}

void _union(int node1, int node2){
    int parent1 = find(node1);
    int parent2 = find(node2);
    
    parent[parent1] = parent2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    
    vector<int> vec(n);
    for(int i =0;i<m;i++){
        cin >> vec[i];    
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i =0;i<n;i++) parent[i] = i;
    
    int temp;
    auto it = vec.begin();
    for(int i =0;i<k;i++){
        cin >> temp;
        int index = upper_bound(vec.begin(), vec.end(), temp) - vec.begin();
        int parent_index = find(index);
        cout << vec[parent_index] << '\n';
        _union(parent_index, parent_index+1);
    }
    
    return 0;
}