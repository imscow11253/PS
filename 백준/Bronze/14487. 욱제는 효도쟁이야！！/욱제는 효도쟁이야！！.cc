#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int sum=0;
  int value =0;
  for(int i =0;i<n;i++){
    int temp;
    cin >> temp;
    sum += temp;
    value = max(value, temp);
  }
  
  cout << sum - value;
  
  return 0;
}