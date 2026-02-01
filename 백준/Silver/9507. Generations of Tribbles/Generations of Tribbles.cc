#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  long long arr[68];
  
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;
  int lastUpdated=3;
  
  while(t--){
    int temp;
    cin >> temp;
    if(temp <= lastUpdated){
      cout << arr[temp] << '\n';
      continue;
    }
    for(int i =lastUpdated+1; i <= temp; i++){
      arr[i] = arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4];
    }
    lastUpdated = temp;
    cout << arr[temp] << '\n';
  }
  
  return 0;
}