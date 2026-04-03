#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n=0;
  int sum =0;
  while(n != -1){
    sum += n;
    cin >> n;
  }
  
  cout << sum;
  
  return 0;
}