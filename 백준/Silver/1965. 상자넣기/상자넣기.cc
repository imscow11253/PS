#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  vector<int> vec;
  for(int i =0;i<n;i++){
    int temp;
    cin >> temp;
    
    auto it = lower_bound(vec.begin(), vec.end(), temp);
    if(it == vec.end()) vec.push_back(temp);
    else *it = temp;
  }
  
  cout << vec.size();
  
  return 0;
}