#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
int arr[500][500] = {0,};
bool visit[500][500] = {0,};
int num =0;
int result=0;

void bfs(int r, int c){
  queue<pair<int,int>> qu;
  qu.push({r,c});
  visit[r][c] = true;
  
  int temp =0;
  while(!qu.empty()){
    auto p = qu.front();
    qu.pop();
    
    int row = p.first;
    int col = p.second;
    
    // cout << row << " " << col << '\n';
    
    temp++;
    if(row -1 >=0 && arr[row-1][col] == 1 && !visit[row-1][col]){
      visit[row-1][col] = true;
      qu.push({row-1, col});
    }
    if(col -1 >=0 && arr[row][col-1] == 1 && !visit[row][col-1]){
      visit[row][col-1] = true;
      qu.push({row, col-1});
    }
    if(row +1 < n && arr[row+1][col] == 1 && !visit[row+1][col]){
      visit[row+1][col] = true;
      qu.push({row+1, col});
    }
    if(col +1 < m && arr[row][col+1] == 1 && !visit[row][col+1]){
      visit[row][col+1] = true;
      qu.push({row, col+1});
    }
  }
  
  result = max(result, temp);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for(int i =0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> arr[i][j];
    }
  }
  
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
      if(visit[i][j] || arr[i][j] == 0) continue;
      num++;
      bfs(i,j);
    }
  }
  
  cout << num << '\n' << result;
  
  return 0;
}