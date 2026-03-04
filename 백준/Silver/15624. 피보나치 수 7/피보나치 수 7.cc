#include <iostream>

using namespace std;

int divide = 1000000007;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  long long dp[1000001]={0,};
  dp[1]=1;

  for(int i =2;i<=n;i++){
    dp[i] = (dp[i-2] + dp[i-1])%divide;
  }  
  
  cout << dp[n];
  
  return 0;
}