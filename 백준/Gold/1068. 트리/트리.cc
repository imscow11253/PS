#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> node[50];
bool cutted_node[50] ={};
int leaf=0;
int root;
int cut;

void avail_dfs(int cur_node){
    cutted_node[cur_node] = true;
    for(int a : node[cur_node]){
        avail_dfs(a);
    }
}

void dfs(int cur_node){
    int check=0;
    if(cutted_node[cur_node]) return;
    if(node[cur_node].size()==0){
        leaf++;
    }
    else{
        for(int a : node[cur_node]){
            if(!cutted_node[a]) {
                check=1;
                dfs(a);
            }
        }
        if(!check) leaf++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(temp == -1){
            root = i;
        }
        else node[temp].push_back(i);
    }
    cin >> cut;
    
    avail_dfs(cut);
    dfs(root);
    
    cout << leaf;
    
    return 0;
}