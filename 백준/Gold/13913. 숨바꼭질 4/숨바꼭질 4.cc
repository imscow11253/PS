#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
int arr[100001] = {0,};
bool visit[100001] = {0,};

void bfs(){
  queue<int> qu;
  qu.push(n);
  visit[n] = true;
  
  while(!qu.empty()){
    int node = qu.front();
    qu.pop();
    
    if(node == k) return;
    
    if(node -1 >= 0 && !visit[node-1]){
      visit[node-1] = true;
      arr[node-1] = node;
      qu.push(node-1);
    }
    if(node +1 <= 100000 && !visit[node+1]){
      visit[node+1] = true;
      arr[node+1] = node;
      qu.push(node+1);
    }
    if(node *2 <= 100000 && !visit[node*2]){
      visit[node*2] = true;
      arr[node*2] = node;
      qu.push(node*2);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;
  bfs();
  
  int temp =k;
  vector<int> vec;
  vec.push_back(temp);
  while(temp != n){
    temp = arr[temp];
    vec.push_back(temp);
  }
  
  cout << vec.size()-1 << '\n';
  for(int i = vec.size()-1; i>=0; i--){
    cout << vec[i] << " ";
  }
  
  return 0;
}