#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  unordered_map<string, set<string>> teams;
  unordered_map<string, string> members;
  
  while(n--){
    string team;
    cin >> team;
    
    int num;
    cin >> num;
    while(num--){
      string name;
      cin >> name;
      
      teams[team].insert(name);
      members[name] = team;
    }
  }
  
  while(m--){
    string temp;
    cin >> temp;
    int order;
    cin >> order;
    if(order){
      cout << members[temp] << '\n';
    }
    else{
      for(const string& str : teams[temp]){
        cout << str << '\n';
      }
    }
  }
  
  return 0;
}