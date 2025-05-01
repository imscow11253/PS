#include <iostream>
#include <queue>
#include <climits>
#include <map>

using namespace std;

int n,m;
map<int,int> graph[1001];
int from, to;
long long distance_value[1001];
bool visit[1001] = {0,};

struct compare{
    bool operator()(pair<long long,int> a, pair<long long,int> b){
        return a.first > b.first;
    }
};

void dijkstra(){
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, compare> qu; // distance, nextNode
    qu.push({0,from});
    visit[from] = true;
    
    while(!qu.empty()){
        auto a = qu.top();
        qu.pop();
        
        long long length = a.first;
        int nextNode = a.second;
        distance_value[nextNode] = min(length, distance_value[nextNode]);
        // cout << nextNode << " " << distance_value[nextNode] << '\n';
        visit[nextNode] = true;
        
        for(auto b : graph[nextNode]){
            if(visit[b.first]){
                continue;
            }
            qu.push({length + b.second, b.first});
        }
        
        int check =1;
        for(int i =1;i<=n;i++){
            if(!visit[i]) check=0;
        }
        if(check) return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    int sta,en,value;
    while(m--){
        cin >> sta >> en >> value;
        if(graph[sta].find(en) != graph[sta].end()){
            graph[sta][en] = min(graph[sta][en], value);
        }
        else graph[sta].insert({en, value});
    }
    cin >> from >> to;
    
    for(int i=1;i<=n;i++) distance_value[i] = LONG_LONG_MAX;
    dijkstra();
    // for(int i =1;i<=n;i++){
    //     cout << distance_value[i] << " ";
    // }cout << '\n';
    cout << distance_value[to];
    
    return 0;
}