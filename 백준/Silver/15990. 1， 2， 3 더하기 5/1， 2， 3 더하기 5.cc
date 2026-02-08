#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  
  int divide = 1000000009;
  
  long long dp[3][100001]={0,};
  dp[0][1] = 1;
  dp[1][2] = 1;
  dp[0][3] = 1;
  dp[1][3] = 1;
  dp[2][3] = 1;
  int index = 3;
  while(t--){
    int num;
    cin >> num;
    
    if(num <= index){
      cout << (dp[0][num] + dp[1][num] + dp[2][num]) % divide << '\n';
      continue;
    }
    
    for(int i = index+1; i <= num; i++){
      dp[0][i] = (dp[1][i-1] + dp[2][i-1]) % divide;
      dp[1][i] = (dp[0][i-2] + dp[2][i-2]) % divide;
      dp[2][i] = (dp[0][i-3] + dp[1][i-3]) % divide;
    }
    index = num;
    cout << (dp[0][num] + dp[1][num] + dp[2][num]) % divide << '\n';   
  }
  
  return 0;
}