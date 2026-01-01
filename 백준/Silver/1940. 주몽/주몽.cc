#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  
  vector<int> vec(n);
  for(int i =0;i<n;i++){
    cin >> vec[i];
  }
  
  sort(vec.begin(), vec.end());
  int l=0,r=n-1;
  int result=0;
  while(l < r){
    if(vec[l] + vec[r] == m){
      result++;
      l++;
    }
    else if(vec[l] + vec[r] < m){
      l++;
    }
    else{
      r--;
    }
  }
  
  cout << result;
  
  return 0;
}