#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <climits>

using namespace std;

int n;
long long arr[100000];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =0;i<n;i++) cin >> arr[i];
  sort(arr, arr+n);
  
  int left = 0;
  int right = n-1;
  int left_result;
  int right_result;
  int value = INT_MAX;
  
  while(left < right){
    if(abs(arr[left] + arr[right]) < value){
      left_result = arr[left];
      right_result = arr[right];
      value = abs(arr[left] + arr[right]);
    }
    
    if(arr[left] + arr[right] < 0) left++;
    else right--;
  }  
      
  
  cout << left_result << " " << right_result;
  
  return 0;
}