#include <iostream>

using namespace std;

int main(){
  int price;
  int num;
  int money;
  
  cin >> price >> num >> money;
  int result = price * num;
  if(money - result >= 0) cout << 0;
  else cout << result - money;
}