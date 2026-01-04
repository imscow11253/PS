#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> graph[1000001];
int result=0;

bool recursive(int node, int parent){
  // cout << node << '\n';
  if(graph[node].size() == 0) return false;
  
  int check =0;
  for(const auto& child : graph[node]){
    if(child == parent) continue;
    
    if(!recursive(child, node)) {
      check =1;
    }
  }
  if(check) {result++;  return true;}
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  int sta, en;
  for(int i =1;i<n;i++){
    cin >> sta >> en;
    graph[sta].push_back(en);
    graph[en].push_back(sta);
  }
  
  recursive(1, 0);
  cout << result;
  
  return 0;
}