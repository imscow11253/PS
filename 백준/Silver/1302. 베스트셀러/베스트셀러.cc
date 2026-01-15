#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  map<string, int> mp;
  
  string str;
  while(n--){
    cin >> str;
    if(mp.find(str) != mp.end()) mp[str]++;
    else mp.insert({str, 1});
  }
  
  string result;
  int value = 0;
  for(auto a : mp){
    if(value < a.second){
      value = a.second;
      result = a.first;
    }
    if(value == a.second && result > a.first){
      value = a.second;
      result = a.first;
    }
  }
  
  cout << result;
  
  
  return 0;
}