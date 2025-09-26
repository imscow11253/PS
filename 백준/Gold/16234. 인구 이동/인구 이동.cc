#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

int n, l, r;
int arr[50][50];

bool bfs(int r1, int c, bool (&visit)[50][50]){
  queue<pair<int,int>> qu;
  qu.push({r1,c});
  visit[r1][c] = true;
  
  int cnt =0;
  int sum =0;
  vector<pair<int,int>> vec;
  
  while(!qu.empty()){
    auto p = qu.front();
    qu.pop();
    
    int row = p.first;
    int col = p.second;
    
    // cout << row << " " << col << '\n';
    
    sum += arr[row][col];
    cnt++;
    vec.push_back({row,col});
    
    if(row-1 >=0 && !visit[row-1][col] && abs(arr[row][col]-arr[row-1][col]) >= l && abs(arr[row][col]-arr[row-1][col]) <= r){
      visit[row-1][col] = true;
      qu.push({row-1,col});
    }
    if(row+1 < n && !visit[row+1][col] && abs(arr[row][col]-arr[row+1][col]) >= l && abs(arr[row][col]-arr[row+1][col]) <= r){
      visit[row+1][col] = true;
      qu.push({row+1,col});
    }
    if(col-1 >=0 && !visit[row][col-1] && abs(arr[row][col]-arr[row][col-1]) >= l && abs(arr[row][col]-arr[row][col-1]) <= r){
      visit[row][col-1] = true;
      qu.push({row,col-1});
    }
    if(col+1 < n && !visit[row][col+1] && abs(arr[row][col]-arr[row][col+1]) >= l && abs(arr[row][col]-arr[row][col+1]) <= r){
      visit[row][col+1] = true;
      qu.push({row,col+1});
    }
  }
  
  if(cnt == 1) return false;
  for(auto a : vec){
    arr[a.first][a.second] = sum/cnt;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> l >> r;
  for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> arr[i][j];
    }
  }
  
  int check = true;
  int day=0;
  while(check){
    check = false;
    bool visit[50][50] = {0,};
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(visit[i][j]) continue;
        // cout << "Start: " << i << " " << j << '\n';
        check |= bfs(i,j, visit);
      }
    }
    if(check) day++;
  }
  cout << day;
  
  return 0;
}