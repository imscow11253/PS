#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  vector<int> vec(n);
  int result = 0;
  for(int i =0;i<n;i++){
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  
  for(int i =0;i<n;i++){
    result = max(result, vec[i] * (n-i));
  }
  
  cout <<result;
  
  return 0;
}