#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k;
vector<int> node[100000];
int arr[200001];
vector<pair<int,int>> edges;
int visit[100000] = {};

bool is_bipartite(int node_num, int color){
    visit[node_num] = color;
    int next_color = (color == 1) ? 2 : 1;
    for(int a : node[node_num]){
        if(visit[a] ==0){
            if(!is_bipartite(a, next_color)){
                return false;
            }
        }
        else if(visit[a] == color){
            return false;
        }
    }
    return true;
}

void clear_visit(){
    for(int i =0;i<n;i++){
        visit[i] = 0;
    }
}

void print(){
    for(int i=0;i<n;i++){
        cout << i << " : ";
        for(int a : node[i]){
            cout << a << " ";
        }cout << '\n';
    }
}


bool is_graph_bipartite() {
    for (int i = 0; i < n; i++) {
        if (visit[i] == 0) { // 방문하지 않은 노드만 체크
            if (!is_bipartite(i, 1)) {
                return false;
            }
        }
    }
    return true;
}

bool process(int mid){
    clear_visit();
    for(int i=1;i<=mid;i++){
        auto edge = edges[arr[i]-1];
        node[edge.first].erase(find(node[edge.first].begin(), node[edge.first].end(), edge.second));
        node[edge.second].erase(find(node[edge.second].begin(), node[edge.second].end(), edge.first));   
    }
    // cout << "remove : " << edge.first << ", " << edge.second << '\n'; 
    // cout << "remove : " << mid << '\n';
    // print();
    bool result = false;
    if(is_graph_bipartite()){
        result =  true;
    }
    
    for(int i=1;i<=mid;i++){
        auto edge = edges[arr[i]-1];
        node[edge.first].push_back(edge.second);
        node[edge.second].push_back(edge.first);
    }
   
    // print();
    // cout << result << '\n';
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    int sta, end;
    for(int i =0;i<m;i++){
        cin >> sta >> end;
        node[sta-1].push_back(end-1);
        node[end-1].push_back(sta-1);
        edges.push_back({sta-1,end-1});
    }
    
    for(int i=1;i<=k;i++){
        cin >> arr[i];
    }
    
    int l = 0, r = k+1;
    while(l < r){
        int mid = (l+r)/2;
        if(process(mid)){
            r = mid; continue;
        }
        l = mid+1;
    }
    
    if (l > k || !process(l)) {
        cout << -1;
        return 0;
    }
        
    cout << l << '\n';
    int num=0;
    for(int j=0;j<n;j++){
        if(visit[j] == 1) num++;
    }
    cout << min(num, n-num) << " " << max(num, n-num);
    
    return 0;
}