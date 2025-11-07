#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10000]= {0,};
int dp[2][10000] = {0,};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =0;i<n;i++) cin >> arr[i];
  
  dp[0][0] = arr[0];
  dp[1][0] = 0;
  dp[0][1] = arr[0] + arr[1];
  dp[1][1] = arr[0];
  
  for(int i =2;i<n;i++){
    dp[0][i] = max(dp[1][i-1], dp[1][i-2] + arr[i-1]);
    dp[0][i] += arr[i];
    dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
  }
  
  cout << max(dp[0][n-1], dp[1][n-1]);
  
  return 0;
}