#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string str;
  cin >> str;
  
  int zero=0, one=0;
  char past = 2;
  for(char a : str){
    if(a == past) continue;
    if(a == '0') zero++;
    else one++;
    past = a;
  }
  cout << min(zero, one);
}