#include <iostream>

using namespace std;

int n,k;
int dp[201][201] = {0,}; //n,k
int divide = 1000000000;

int recursive(int num, int _k){
  if(dp[num][_k] != 0) return dp[num][_k];
  
  long long result=0;
  for(int i =0;i<=num;i++){
    result += recursive(num-i, _k-1);
    result %= divide;
  }
  
  return dp[num][_k] = result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;
  for(int i =0;i<=n;i++){
    dp[i][1] = 1;
  }
  
  cout << recursive(n,k);
  
  return 0;
}