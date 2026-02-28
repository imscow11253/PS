#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int w,h;

void bfs(int r, int c, bool visit[50][50], int arr[50][50]){
  queue<pair<int,int>> qu;
  qu.push({r,c});
  visit[r][c] = true;
  
  while(!qu.empty()){
    auto p = qu.front();
    qu.pop();
    
    int row = p.first;
    int col = p.second;
    
    if(row-1>=0 && !visit[row-1][col] && arr[row-1][col] == 1){
      visit[row-1][col] = true;
      qu.push({row-1, col});
    }
    if(row+1<w && !visit[row+1][col] && arr[row+1][col] == 1){
      visit[row+1][col] = true;
      qu.push({row+1, col});
    }
    if(col-1>=0 && !visit[row][col-1] && arr[row][col-1] == 1){
      visit[row][col-1] = true;
      qu.push({row, col-1});
    }
    if(col+1<h && !visit[row][col+1] && arr[row][col+1] == 1){
      visit[row][col+1] = true;
      qu.push({row, col+1});
    }
    
    if(row-1>=0 && col-1>=0 && !visit[row-1][col-1] && arr[row-1][col-1] == 1){
      visit[row-1][col-1] = true;
      qu.push({row-1, col-1});
    }
    if(row+1<w && col-1>=0 && !visit[row+1][col-1] && arr[row+1][col-1] == 1){
      visit[row+1][col-1] = true;
      qu.push({row+1, col-1});
    }
    if(row-1>=0 && col+1<h && !visit[row-1][col+1] && arr[row-1][col+1] == 1){
      visit[row-1][col+1] = true;
      qu.push({row-1, col+1});
    }
    if(row+1<w && col+1<h && !visit[row+1][col+1] && arr[row+1][col+1] == 1){
      visit[row+1][col+1] = true;
      qu.push({row+1, col+1});
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> h >> w;
  
  int arr[50][50];
  while(w != 0 || h != 0){
    
    for(int i =0;i<w;i++){
      for(int j=0;j<h;j++){
        cin >> arr[i][j];
      }
    }
    
    bool visit[50][50] = {0,};
    int result=0;
    for(int i =0;i<w;i++){
      for(int j=0;j<h;j++){
        if(arr[i][j] == 0) visit[i][j] = true;
        if(visit[i][j]) continue;
        bfs(i,j, visit, arr);
        result++;
        // cout << i << " " << j << '\n';
      }
    }
    
    cout << result << '\n';
    cin >> h >> w;
  }
  
  return 0;
}