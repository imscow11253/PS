#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  int dp[10][1001];
  for(int i =0;i<10;i++) dp[i][1] = i+1;
  
  for(int i =2;i<=n;i++){
    for(int j =0;j<10;j++){
      if(j == 0) dp[j][i] = dp[j][i-1];
      else{
        dp[j][i] = (dp[j][i-1] + dp[j-1][i]) % 10007;
      }
    }
  }
  
  cout << dp[9][n];
  
  return 0;
}