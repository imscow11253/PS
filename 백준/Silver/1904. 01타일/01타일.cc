#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  int dp[1000001] = {0,};
  dp[1] = 1;
  dp[2] = 2;
  for(int i =3;i<=n;i++){
    dp[i] = (dp[i-1] + (dp[i-2]))%15746;
  }
  
  cout << dp[n];
  
  return 0;
}