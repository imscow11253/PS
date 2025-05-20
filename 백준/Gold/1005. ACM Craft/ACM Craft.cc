#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
int timeToBuild[1001];
vector<int> graph[1001];
int enter[1001];
int w;
int real_build_time[1001];

int dag(){
    queue<pair<int,int>> qu; //node, cnt
    
    for(int i =1;i<=n;i++){
        real_build_time[i] = timeToBuild[i];;
        if(enter[i] ==0) qu.push({i, 1});
    }
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int node = a.first;
        int cnt = a.second;
        
        for(int child : graph[node]){
            real_build_time[child] = max(real_build_time[child], real_build_time[node] + timeToBuild[child]);
            enter[child]--;
            if(enter[child]==0)qu.push({child, cnt+1});
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        cin >> n >> k;
        for(int i =0;i<1001;i++){
            graph[i].clear(); timeToBuild[i] = 0;enter[i]=0;real_build_time[i] =0;
        }
        for(int i =1;i<=n;i++){
            cin >> timeToBuild[i];
            graph[i].clear();
            enter[i]=0;
        }
        int a,b;
        for(int i=0;i<k;i++){
            cin >> a >> b;
            graph[a].push_back(b);
            enter[b]++;
        }
        
        cin >> w;
        int cnt = dag();
        // int result =0;
        // for(int i =1;i<=cnt;i++){
        //     // cout << real_build_time[i] << " ";
        //     result += real_build_time[i];
        // }
        // // cout << '\n';
        cout << real_build_time[w] << '\n';
    }
    
    return 0;
}