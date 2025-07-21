#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<set<int>> graph(n+1);
        vector<int> degree(n+1, 0);
        
        vector<int> vec(n);
        for(int i =0;i<n;i++){
            cin >> vec[i];
            degree[vec[i]] = i;
            for(int j=0;j<i;j++) graph[vec[j]].insert(vec[i]);
        }
        
        int m;
        cin >> m;
        int node1, node2;
        for(int i =0;i<m;i++){
            cin >> node1 >> node2;
            if(graph[node1].find(node2) != graph[node1].end()){
                graph[node1].erase(node2);
                graph[node2].insert(node1);
                degree[node1]++;
                degree[node2]--;
            }
            else if(graph[node2].find(node1) != graph[node2].end()){
                graph[node2].erase(node1);
                graph[node1].insert(node2);
                degree[node2]++;
                degree[node1]--;
            }
        }
        
        int cnt=0;
        vector<bool> visit(n+1, false);
        vector<int> result;
        bool dfdf = true;
        while(cnt < n){
            int check=0;
            int index=0;
            for(int i =1;i<=n;i++){
                if(!visit[i] && degree[i] == 0){
                    check++;
                    index = i;
                }
            }
            if(check < 1) {cout << "IMPOSSIBLE\n"; dfdf = false; break;}
            if(check > 1) {cout << "?\n"; dfdf = false; break;}
            result.push_back(index);
            visit[index] = true;
            for(int a : graph[index]){
                degree[a]--;
            }
            cnt++;
        }
        
        if(dfdf){
            for(int a : result) cout << a << " ";
            cout << '\n';   
        }
    }
    
    return 0;
}