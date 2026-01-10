#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a,b;
  int a_result=100, b_result=100;
  while(n--){
    cin >> a >> b;
    if(a  == b) continue;
    if(a < b) a_result -= b;
    else b_result -= a;
  }
  
  cout << a_result << '\n' << b_result;
}