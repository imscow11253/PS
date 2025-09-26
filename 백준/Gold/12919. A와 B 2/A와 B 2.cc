#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

string init, target;

int bfs(){
  queue<string> qu;
  qu.push(target);
  
  while(!qu.empty()){
    string str = qu.front();
    qu.pop();
    
    // cout << str << '\n';
    if(str == init) return 1;
    if(str.length() == 1) continue;
    
    if(str[0] == 'B'){
      string new_str = str;
      reverse(new_str.begin(), new_str.end());
      qu.push(new_str.substr(0,new_str.length()-1));
    }
    if(str[str.length()-1] == 'A'){
      qu.push(str.substr(0,str.length()-1));
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> init >> target;
  cout << bfs();
  
  return 0;
}