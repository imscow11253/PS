#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    vector<int> vec;
    int temp;
    for(int i =0;i<7;i++){
      cin >> temp;
      if(temp % 2 ==0) vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    int sum=0;
    for(int a : vec) sum += a;
    cout << sum << " " << vec[0] << '\n';
  }
  
  return 0;
}