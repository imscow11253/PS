#include <iostream>
#include <string>

using namespace std;

int divide = 1000000;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string str;
  cin >> str;
  
  if(str[0] == '0'){
    cout << 0;
    return 0;
  }
  
  int dp[5001] = {0,};
  dp[0] = 1;
  dp[1] = 1;
  
  for(int i =1;i<=str.length();i++){
    int check = true;
    
    if(str[i-1] != '0'){
      string temp = "";
      temp += str[i-1]; 
      temp += str[i];
      int twoAgo = stoi(temp);
      if(twoAgo <= 26){
        dp[i+1] += dp[i-1];
        dp[i+1] %= divide;
        check = false;
      } 
    }
    
    if(str[i] != '0'){
      dp[i+1] += dp[i];
      dp[i+1] %= divide;
      check = false;
    }
    
    if(check){
      cout << 0;
      return 0;
    }
  }
  
  // for(int i =1;i<=str.length(); i++) cout << dp[i] << " ";
  // cout << '\n';
  
  cout << dp[str.length()];
  
  return 0;
}