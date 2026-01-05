#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n,m;

int arr[100001];
int max_tree[400001];
int min_tree[400001];

pair<int,int> make_tree(int node, int left, int right){
  if(left == right){
    max_tree[node] = arr[left];
    min_tree[node] = arr[left];
    return {max_tree[node], min_tree[node]};
  }
  
  int mid = (left + right) /2;
  auto left_result = make_tree(node * 2, left, mid);
  auto right_result = make_tree(node * 2 + 1, mid + 1, right);
  
  max_tree[node] = max(left_result.first, right_result.first);
  min_tree[node] = min(left_result.second, right_result.second);
  
  return {max_tree[node], min_tree[node]};
}

pair<int,int> query(int node, int left, int right, const int& sta, const int& en){
  if(en < left || sta > right) 
    return {INT_MIN, INT_MAX};

  if(sta <= left && right <= en) return {max_tree[node], min_tree[node]};
  
  int mid = (left + right) / 2;
  
  auto left_result = query(node * 2, left, mid, sta, en);
  auto right_result = query(node * 2 + 1, mid + 1, right, sta, en);
  
  int M = max(left_result.first, right_result.first);
  int m = min(left_result.second, right_result.second);
  
  return {M,m};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for(int i =1;i<=n;i++){
    cin >> arr[i];
  }
  
  make_tree(1, 1, n);
  
  int sta, en;
  while(m--){
    cin >> sta >> en;
    auto p = query(1, 1, n, sta, en);
    cout << p.second << " " << p.first << '\n';
  }
  
  return 0;
}