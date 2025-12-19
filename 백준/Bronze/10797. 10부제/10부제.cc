#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  
  int result=0;
  for(int i =0;i<5;i++){
    int temp;
    cin >> temp;
    if(temp == n) result++;
  }
  
  cout << result;
  return 0;
}