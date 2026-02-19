#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string str, str2;
  cin >> str >> str2;
  
  long long result=0;
  for(char a : str){
    for(char b : str2){
      result += (a - '0') * (b - '0');
    }
  }
  
  cout << result;
  
  return 0;
}