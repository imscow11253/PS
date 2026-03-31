#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string str;
  cin >> str;
  
  vector<string> vec;
  for(int i =0;i<str.length();i++){
    string temp = str.substr(i, str.length());
    vec.push_back(temp);
  }
  
  sort(vec.begin(), vec.end());
  
  for(string temp : vec) cout << temp << '\n';
  
  return 0;
}