#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int arr[1000];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int dp[1000];
  for(int i = 0; i < n; i++) dp[i] = INT_MAX;

  dp[0] = 0;

  for(int i = 0; i < n; i++){
    if(dp[i] == INT_MAX) continue;

    for(int j = 1; j <= arr[i] && i + j < n; j++){
      dp[i+j] = min(dp[i+j], dp[i] + 1);
    }
  }

  if(dp[n-1] == INT_MAX) cout << -1;
  else cout << dp[n-1];

  return 0;
}