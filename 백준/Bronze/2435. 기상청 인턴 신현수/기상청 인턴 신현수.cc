#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,k;
  cin >> n >> k;
  int arr[100];
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  
  int value =0;
  for(int i =0;i<k;i++){
    value += arr[i];
  }
  int result = value;
  
  for(int i = k; i<n;i++){
    value += arr[i];
    value -= arr[i-k];
    result = max(result, value);
  }
  
  cout << result;
  
  return 0;
}