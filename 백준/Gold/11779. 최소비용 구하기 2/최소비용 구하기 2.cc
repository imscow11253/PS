#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
map<int,int> graph[1001];
int start_node, end_node;
int prev_node[1001] = {0,};
int dist[1001]={0,};

void dijstra(){
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq; // distance, node, prev_node
    pq.push(make_tuple(0,start_node, -1));
    
    fill(dist, dist + 1001, INT_MAX);
    dist[start_node] = 0;
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        
        int distance = get<0>(a);
        int node = get<1>(a);
        int prev = get<2>(a);
        
        if (dist[node] < distance) continue;
        
        dist[node] = distance;
        prev_node[node] = prev;
        
        if(node == end_node) return;
        for(auto p : graph[node]){
            int next = p.first;
            int cost = p.second;
            if (dist[next] > distance + cost) {
                dist[next] = distance + cost;
                pq.push({dist[next], next, node});
            }
        }
    }
}

vector<int> get_path_nodes(){
    vector<int> result;
    
    int node = end_node;
    result.push_back(node);
    while(node != start_node){
        result.push_back(prev_node[node]);
        node = prev_node[node];
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int sta, en, value;
    while(m--){
        cin >> sta >> en >> value;
        if(graph[sta].find(en) != graph[sta].end())
            graph[sta][en] = min(graph[sta][en], value);
        else
            graph[sta][en] = value;
    }

    cin >> start_node >> end_node;
    dijstra();

    cout << dist[end_node] << '\n';
    auto result = get_path_nodes();
    cout << result.size() << '\n';
    for(int a : result) cout<< a << " ";

    return 0;
}