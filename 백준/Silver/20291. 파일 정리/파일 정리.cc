#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  map<string, int> mp;
  
  cin >>n;
  for(int i =0;i<n;i++){
    string str;
    cin >> str;
    
    int it = str.find('.');
    string file = str.substr(it+1);
    
    if(mp.find(file) != mp.end()) mp[file]++;
    else mp.insert({file, 1});
  }
  
  for(auto p : mp){
    cout << p.first << " ";
    cout << p.second << '\n';
  }
  
  return 0;
}