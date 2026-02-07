#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int arr[100000];
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  
  int dp[100000] = {0,};
  dp[0] =1;
  int result =1;
  for(int i =1;i<n;i++){
    if(arr[i-1] <= arr[i]) dp[i] = dp[i-1] +1;
    else dp[i] = 1;
    result = max(result, dp[i]);
  }
  
  int _dp[100000] = {0,};
  _dp[0] =1;
  for(int i =1;i<n;i++){
    if(arr[i-1] >= arr[i]) dp[i] = dp[i-1] +1;
    else dp[i] = 1;
    result = max(result, dp[i]);
  }
  
  
  cout << result;
  
  return 0;
}