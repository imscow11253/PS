#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000];
int left_dp[1000] = {0,};
int right_dp[1000] = {0,};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  
  left_dp[0] = 1;
  for(int i =1;i<n;i++){
    int temp =0;
    for(int j =0;j<i;j++){
      if(arr[j] < arr[i] && temp < left_dp[j]) temp = left_dp[j];
    }
    left_dp[i] = temp + 1;
  }
  
  right_dp[n-1] = 1;
  for(int i =n-2;i>=0;i--){
    int temp =0;
    for(int j =n-1;j>i;j--){
      if(arr[j] < arr[i] && temp < right_dp[j]) temp = right_dp[j];
    }
    right_dp[i] = temp + 1;
  }
  
  // for(int i =0;i<n;i++){
  //   cout << left_dp[i] << " ";
  // }cout << '\n';
  // for(int i =0;i<n;i++){
  //   cout << right_dp[i] << " ";
  // }cout << '\n';
  
  int result =0;
  for(int i =0;i<n;i++){
    result = max(result, left_dp[i] + right_dp[i] -1);
  }
  
  cout << result;
  
  return 0;
}