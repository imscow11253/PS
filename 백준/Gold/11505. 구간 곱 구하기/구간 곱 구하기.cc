#include <iostream>
#include <algorithm>

using namespace std;

int n,m,k;
long long arr[1000001];
long long tree[4000001];
int devide = 1000000007;

long long make_tree(int node, int left, int right){
  if(left == right) 
    return tree[node] = arr[left];
    
  int mid = (left+right)/2;
  
  return tree[node] = (make_tree(node*2, left, mid) * make_tree(node*2+1, mid+1, right)) % devide;
}

void update(int node, int left, int right, const int& index, const int& value){
  if(index < left || index > right) return;
  
  if(left == right && left == index){
    tree[node] = value;
    return ;
  }
  
  int mid = (left+right)/2;
  
  if(index >= left && index <= mid) update(node*2, left, mid, index, value);
  else update(node*2+1, mid+1, right, index, value);
  
  tree[node] = (tree[node*2] * tree[node*2+1]) % devide;
}

long long query(int node, int left, int right, const int& sta, const int& en){
  if(en < left || right < sta) return 1;
  if(sta <= left && right <= en) return tree[node];
  
  int mid = (left+right) /2;
  
  return (query(node*2, left, mid, sta, en) * query(node*2+1, mid+1, right, sta, en)) % devide;
}


int main (){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m >> k;
  for(int i =1;i<=n;i++) cin >> arr[i];
  
  make_tree(1, 1, n);
  
  int a,b,c;
  for(int i =0;i<m+k;i++){
    cin >> a >> b >> c;
    if(a == 1) update(1,1,n,b,c);
    else cout << query(1,1,n,b,c) << '\n';
  }
  
  return 0;
}