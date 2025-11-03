#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n,k;
vector<int> coin;

int dp[10001];
bool visit[10001] = {0,};

int recursive(int k){
  if(dp[k] != -1) return dp[k];
  if(visit[k]) return dp[k];
  
  int result = INT_MAX;
  for(int a : coin){
    if(k - a >= 0){
      int temp = recursive(k - a);
      if(temp == -1) continue;
      result = min(result, recursive(k - a) + 1); 
    }
  }
  
  if(result == INT_MAX) result = -1;
  dp[k] = result;
  visit[k] = true;
  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;
  int temp;
  for(int i =0;i<n;i++){
    cin >> temp;
    coin.push_back(temp);
  }
  
  for(int i =0;i<=k;i++){
    dp[i] = -1;
  }
  
  for(int a : coin){
    if(a > 10000) continue;
    dp[a] = 1;
  }
  
  cout << recursive(k);
  
  return 0;
}