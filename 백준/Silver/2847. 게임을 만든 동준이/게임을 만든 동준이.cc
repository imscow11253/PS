#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  int arr[100];
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  
  int result =0;
  for(int i = n-2; i >= 0; i--){
    int value = arr[i+1];
    if(arr[i] >= value){
      result += ((arr[i] - value) + 1);
      arr[i] = value -1;
    }
  }
  cout << result;
  
  return 0;
}