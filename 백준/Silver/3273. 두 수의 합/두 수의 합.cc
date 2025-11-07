#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int x;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =0;i<n;i++) cin >> arr[i];
  cin >> x;
  
  sort(arr, arr+n);
  
  int left =0;
  int right = n-1;
  int result =0;
  while(left < right){
    if(arr[left] + arr[right] == x) {result++; left++;}
    else if(arr[left] + arr[right] < x) left++;
    else right--;
  }
  
  cout << result;
  
  return 0;
}