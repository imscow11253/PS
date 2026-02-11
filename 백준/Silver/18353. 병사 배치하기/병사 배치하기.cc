#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  int arr[2000];
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  
  vector<int> vec;
  for(int i =n-1;i>=0;i--){
    vec.push_back(arr[i]);
  }
  
  vector<int> lis;
  for(int i =0;i<n;i++){
      auto it = lower_bound(lis.begin(), lis.end(), vec[i]);
      if(it == lis.end()) lis.push_back(vec[i]);
      else *it = vec[i];
  }
  
  cout << n - (int)lis.size();
  
  return 0;
}