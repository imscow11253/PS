#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int _rank[200000];
int parent[200000];
unordered_map<string, int> nodes;

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
    
    int t;
    cin >> t;
    
    int n;
    while(t--){
        cin >> n;
        nodes.clear();
        int node_num =0;
        
        for(int i =0;i<n;i++){
            string person1, person2;
            cin >> person1 >> person2;
            
            int node1, node2;
            if(nodes.find(person1) == nodes.end()){
                nodes[person1] = node_num;
                node1 = node_num;
                _rank[node_num] = 1;
                parent[node_num] = node_num;
                node_num++;
            }
            else{
                node1 = nodes[person1];
            }
            if(nodes.find(person2) == nodes.end()){
                nodes[person2] = node_num;
                node2 = node_num;
                _rank[node_num] = 1;
                parent[node_num] = node_num;
                node_num++;
            }
            else{
                node2 = nodes[person2];
            }
            
            // cout << find(node1) << " " << find(node2) << '\n'; 
            if(find(node1) != find(node2)) _union(node1, node2);
            
            // for(int i =0;i<node_num;i++) cout << parent[i] << " "; cout << '\n';
            // for(auto a : nodes) cout << a.first << " " << a.second << '\n';
            
            cout << _rank[find(node1)] << '\n';   
        }
    }
    
    return 0;
}