#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int left=1, right=1;
  int result =1;
  int value =1;
  while(left < n || right < n){
    if(value == n){
      result++;
      right++;
      value += right;
    }
    else if(value < n){
      right++;
      value += right;     
    }
    else {
      value -= left;
      left++;
    }
  }
  cout << result;
  
  return 0;
}