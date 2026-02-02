#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  
  vector<int> lis;
  int temp, result=0;
  for(int i =0;i<n;i++){
    cin >> temp;
    auto it = lower_bound(lis.begin(), lis.end(), temp);
    if(it == lis.end()) lis.push_back(temp);
    else{
      *it = temp;
    }
    result = max(result, (int)lis.size());
  }
  
  cout << n-result;
  
  return 0;
}