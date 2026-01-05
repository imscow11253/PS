#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n,m;
int arr[100001];
int tree[400001];

int make_tree(int node, int left, int right){
  if(left == right) return tree[node] = left;
  
  int mid = (left +right)/2;
  int left_result = make_tree(node*2, left, mid);
  int right_result = make_tree(node*2+1, mid+1, right);
  return tree[node] = (arr[left_result] <= arr[right_result]) ? left_result :right_result;
}

void update(int node, int left, int right, const int& index, const int& value){
  if(index < left || index > right) return ;
  if(left == right && left == index) {
    tree[node] = index;
    arr[index] = value;
    return ;
  }
  
  int mid = (left+right) /2;
  
  if(index >= left && index <= mid) update(node*2, left, mid, index, value);
  else update(node*2+1, mid+1, right, index, value);
  
  tree[node] = (arr[tree[node*2]] <= arr[tree[node*2+1]]) ? tree[node*2] : tree[node*2+1];
}

int query(int node, int left, int right, const int& sta, const int& en){
  if(en < left || sta > right) return 0;
  if(sta <= left && right <= en) return tree[node];
  
  int mid = (left+right)/2;
  
  int left_result = query(node*2, left, mid, sta, en);
  int right_result= query(node*2+1, mid+1, right, sta, en);
  
  return (arr[left_result] <= arr[right_result]) ? left_result :right_result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =1;i<=n;i++){
    cin >> arr[i];
  }
  
  arr[0] = INT_MAX;
  make_tree(1,1,n);
  
  cin >> m;
  int a,b,c;
  while(m--){
    cin >> a >> b >> c;
    if(a==1) update(1,1,n,b,c);
    else cout << query(1,1,n,b,c) << '\n';
  }
  
  return 0;
}