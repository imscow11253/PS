#include <iostream>
#include <vector>

using namespace std;

int v,e;
vector<int> graph[10001];
vector<int> reverse_graph[10001];
vector<int> vec;
bool visit[10001] = {0,};

void dfs(int node){
  visit[node] = true;
  for(const int& target : graph[node]){
    if(!visit[target]){
      dfs(target); 
    }
  }
  vec.push_back(node);
}

void first(){
  for(int i =1;i<=v;i++){
    if(!visit[i]) dfs(i);
  }
}

int index =1;
int scc[10001];

void dfs2(int node){
  visit[node] = true;
  scc[node] = index;
  for(const int& target : reverse_graph[node]){
    if(!visit[target]){
      dfs2(target);
    }
  }
}

void second(){
  for(int i = vec.size()-1; i>=0; i--){
    if(!visit[vec[i]]) {
      dfs2(vec[i]);
      index++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> v >> e;
  int a, b;
  while(e--){
    cin >> a >> b;
    graph[a].push_back(b);
    reverse_graph[b].push_back(a);
  }
  
  first();
  for(int i =1;i<=v;i++) visit[i] = 0;
  second();
  
  bool vi[10001] = {0,};
  cout << index-1 << '\n';
  for(int i =1;i<=v;i++){
    if(!vi[i]){
      for(int j = i; j<=v;j++){
        if(scc[j] == scc[i]){
          cout << j << " ";
          vi[j] = true;
        }
      }
      cout << -1 << '\n';
    }
}
  
  return 0;
}