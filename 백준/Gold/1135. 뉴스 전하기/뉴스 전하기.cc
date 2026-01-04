#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<int, vector<int>> graph;
int result=0;
int parent[50] ={0,};

int recursive(int node){
  if(graph.find(node) == graph.end()) return 0;
  vector<int> vec;
  for(const auto& child : graph[node]){
    vec.push_back(recursive(child));
  }
  sort(vec.begin(), vec.end(), greater<>());
  
  int temp=0;
  int weight=1;
  for(int a : vec){
    temp = max(temp, a + weight);
    weight++;
  }
  
  return temp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  int a;
  for(int i =0;i<n;i++){
    cin >> a;
    if(i==0) continue;
    graph[a].push_back(i);
    parent[i] = a;
  }
  parent[0] = -1;
  
  cout << recursive(0);
  
  return 0;
}