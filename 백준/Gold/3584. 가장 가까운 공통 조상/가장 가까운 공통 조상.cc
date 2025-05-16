#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
int target_a, target_b;
vector<int> graph[10001];
int check;

int dfs(int node){
    // cout << "node : " << node <<'\n';
    int result=0;
    if(node == target_a || node == target_b) result += 1;
    for(int child : graph[node]){
        result += dfs(child);
    }
    
    if(result ==2 && check) {
        cout << node << '\n';
        check=0;
    }
    // cout << node << ", " << result <<'\n';
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        for(int i =1;i<=n;i++) graph[i].clear();
        check=1;
        
        int a,b;
        set<int> st;
        for(int i =0;i<n-1;i++){
            cin >> a >> b;
            st.insert(b);
            graph[a].push_back(b);
        }
        
        cin >> target_a >> target_b;
        
        int root;
        for(int i =1;i<=n;i++){
            if(st.find(i) == st.end()){
                root = i;
                break;
            }
        }
        // cout << "root : " << root << '\n';
        dfs(root);
    }
    
    return 0;
}