#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  int t[15];
  int p[15];
  for(int i =0;i<n;i++){
    cin >> t[i] >> p[i];
  }
  
  int dp[16] = {0,};
  if(t[n-1] == 1) dp[n-1] = p[n-1];
  else dp[n-1] = 0;
  
  for(int i = n-2; i>=0; i--){
    if(t[i] <= n - i) dp[i] = max(dp[i+1], dp[i+t[i]] + p[i]);
    else dp[i] = dp[i+1];
  }
  
  // for(int i =0;i<n;i++){
  //   cout << dp[i] << " ";
  // }cout << '\n';
  
  cout << dp[0];
  
  return 0;
}