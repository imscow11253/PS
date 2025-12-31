#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int n,m;
int arr[50][50] = {0,};
int dp[50][50];
bool visit[50][50] = {0,};

int dfs(int row, int col){
  if(dp[row][col] != -1) return dp[row][col];
  
  int result = 0;
  int diff = arr[row][col] - '0';
  
  if(row - diff >=0 && arr[row-diff][col] != 'H'){
    if(visit[row-diff][col]){
      cout << -1; exit(0);
    }
    visit[row-diff][col] = true;
    result = max(result, dfs(row-diff, col) + 1);
    visit[row-diff][col] = false;
  }
  if(col - diff >=0 && arr[row][col-diff] != 'H'){
    if(visit[row][col-diff]){
      cout << -1; exit(0);
    }
    visit[row][col-diff] = true;
    result = max(result, dfs(row, col-diff) + 1);
    visit[row][col-diff] = false;
  }
  if(row + diff <n && arr[row+diff][col] != 'H'){
    if(visit[row+diff][col]){
      cout << -1; exit(0);
    }
    visit[row+diff][col] = true;
    result = max(result, dfs(row+diff, col) + 1);
    visit[row+diff][col] = false;
  }
  if(col + diff <m && arr[row][col+diff] != 'H'){
    if(visit[row][col+diff]){
      cout << -1; exit(0);
    }
    visit[row][col+diff] = true;
    result = max(result, dfs(row, col+diff) + 1);
    visit[row][col+diff] = false;
  }
  
  dp[row][col] = result;
  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for(int i =0;i<n;i++){
    string temp;
    cin >> temp;
    for(int j =0;j<m;j++){
      arr[i][j] = temp[j];
      dp[i][j]=-1;
    }
  }
  
  
  visit[0][0] = true;
  cout << dfs(0,0) + 1;
  
  return 0;
}