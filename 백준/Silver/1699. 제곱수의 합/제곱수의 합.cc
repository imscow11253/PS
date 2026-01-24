#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[100001] = {0,};

int recursive(int num){
  if(dp[num] != 0) return dp[num];
  
  int i =1;
  int result =INT_MAX;
  while(num - (i*i) > 0){
    result = min(result, recursive(num - (i*i)));
    i++;
  }
  
  return dp[num] = result + 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  int i=1;
  while(i * i <= 100000){
    dp[i*i] = 1;
    i++;
  }
  
  cout << recursive(n);
  
  return 0;
}