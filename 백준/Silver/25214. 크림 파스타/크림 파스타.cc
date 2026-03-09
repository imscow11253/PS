#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  int m;
  cin >> m;
  int result = 0;
  cout << result << " ";
  for(int i =1;i<n;i++){
    int temp;
    cin >> temp;
    if(m < temp){
      result = max(result, temp - m);
    }
    m = min(m, temp);
    cout << result << " ";
  }
  
  return 0;
}