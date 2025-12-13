#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int arr[15][15] = {0,};
int dp[15][1 << 15][10] = {0,};
int max_value=0;

void recursive(int status, int node, int price, int num){
  
  // cout << node << '\n';
  
  if (dp[node][status][price] != -1) return;
  dp[node][status][price] = num;
  max_value = max(max_value, num);
  
  for(int i=0;i<n;i++){
    if(status & (1 << i)){
      continue;
    }
    if(arr[node][i] < price){
      continue;
    }
    recursive(status | (1 << i), i, arr[node][i],num+1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  string str;
  for(int i =0;i<n;i++){
    cin >> str;
    for(int j =0 ;j<n;j++){
      arr[i][j] = str[j] - '0';
    }
  }
  
  for(int i =0;i<15;i++){
    for(int j =0;j< 1 << 15; j++){
      for(int k =0 ;k<10;k++){
        dp[i][j][k] = -1;
      }
    }
  }

  recursive(1, 0, 0, 1);
  cout << max_value;
  
  return 0;
}