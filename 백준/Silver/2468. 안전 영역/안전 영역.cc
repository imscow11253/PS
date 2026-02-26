#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[100][100];
int highest=0;
int result=1;

void bfs(int r, int c, bool visit[100][100], int rain){
  queue<pair<int,int>> qu;
  qu.push({r,c});
  
  visit[r][c] = true;
  
  while(!qu.empty()){
    auto p = qu.front();
    qu.pop();
    
    int row = p.first;
    int col = p.second;
    
    if(row -1 >=0 && !visit[row-1][col] && arr[row-1][col] > rain){
      visit[row-1][col] = true;
      qu.push({row-1, col});
    }
    if(row +1 < n && !visit[row+1][col] && arr[row+1][col] > rain){
      visit[row+1][col] = true;
      qu.push({row+1, col});
    }
    if(col -1 >=0 && !visit[row][col-1] && arr[row][col-1] > rain){
      visit[row][col-1] = true;
      qu.push({row, col-1});
    }
    if(col +1 < n && !visit[row][col+1] && arr[row][col+1] > rain){
      visit[row][col+1] = true;
      qu.push({row, col+1});
    }
  }
}

void find(int rain){
  bool visit[100][100] = {0,};
  
  int temp =0;
  
  for(int i =0;i<n;i++){
    for(int j =0;j<n;j++){
      if(arr[i][j] <= rain){
        visit[i][j] = true;
        continue;
      }
      if(visit[i][j]) continue;
      bfs(i,j, visit, rain);
      temp++;    
    }
  }
  
  result = max(result, temp);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> arr[i][j];
      highest = max(highest, arr[i][j]);
    }
  }
  
  for(int i =1;i<=highest; i++){
    find(i);
  }
  
  cout << result;
  
  return 0;
}