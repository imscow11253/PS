#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
int arr[1000][1000];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for(int i =0;i<n;i++){
    string str;
    cin >> str;
    for(int j =0;j<m;j++){
      arr[i][j] = str[j] - '0';
    }
  }
  
  int result=0;
  int dp[1000][1000] = {0,};
  for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
      if(i==0 || j ==0){
        if(arr[i][j] == 1){
          dp[i][j] = 1;
          result = max(result,1);
        }
        continue;
      }
      if(arr[i][j] == 0) continue;
      dp[i][j] =1;
      result = max(result, dp[i][j]);
      if(arr[i-1][j] ==0 ) continue;
      if(arr[i][j-1] == 0) continue;
      if(arr[i-1][j-1] == 0) continue;
      dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) +1;
      result = max(result, dp[i][j]);
    }
  }
  // for(int i =1;i<n;i++){
  //   for(int j =1;j<m;j++){
  //     cout << dp[i][j] << " ";
  //   }cout << '\n';
  // }
  
  cout << result * result;
  
  return 0;
}