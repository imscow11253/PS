#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<bool> dp(n);
  
  dp[0] = false;
  dp[1] = true;
  dp[2] = false;
  for(int i =3;i<n;i++){
    if(!dp[i-1] && !dp[i-3]) dp[i] = true;
    else dp[i] = false;
  }
  
  if(dp[n-1])
  cout << "SK";
  else cout << "CY";
  
  return 0;
}