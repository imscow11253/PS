#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n,d;
unordered_map<int, vector<pair<int,int>>> mp;
int dp[10001];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> d;
  int sta, en, value;
  for(int i =0;i<n;i++){
    cin >> sta >> en >> value;
    mp[en].push_back({sta, value});
  }
  
  dp[0] =0;
  for(int i =1;i<=d;i++){
    int result = dp[i-1] +1;
    if(mp.find(i) != mp.end()){
      auto vec = mp[i];
      for(auto p : vec){
        int before = p.first;
        int weight = p.second;
        result = min(result, dp[before] + weight); 
      }
    }
    
    dp[i] = result;
  }
  
  cout << dp[d];
  
  return 0;
}