#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,k,x;
vector<int> graph[300001];
vector<int> result;
bool visit[300001] = {0,};

void bfs(){
  queue<pair<int,int>> qu;
  qu.push({x,0});
  
  visit[x] = true;
  
  while(!qu.empty()){
    auto p = qu.front();
    qu.pop();
    
    int node = p.first;
    int num = p.second;
    
    if(num == k) {
      result.push_back(node);
      continue;
    }
    
    for(const int& next : graph[node]){
      if(visit[next]) continue;
      qu.push({next, num+1});
      visit[next] = true;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   cin >> n >> m >> k >> x;
   int sta, en;
   while(m--){
     cin >> sta >> en;
     graph[sta].push_back(en);
   }
   
   bfs();
   if(result.size() == 0) cout << -1;
   else{
     sort(result.begin(), result.end());
     for(int a : result) cout << a << '\n';
   }
   
   return 0;
}