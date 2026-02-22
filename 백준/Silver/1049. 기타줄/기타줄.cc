#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  
  int package= INT_MAX, single= INT_MAX;
  while(m--){
    int a,b;
    cin >> a >> b;
    package = min(package, a);
    single = min(single, b);
  }
  
  if(package >= single * 6){
    cout << single*n;
    return 0;
  }
  
  int result =0;
  int i=0;
  while(i * 6 <= n){
    i++;
  }
  i--;
  
  result += package * i;
  n -= i * 6;
  
  if(n * single >= package){
    cout << result + package;
    return 0;
  }
  
  cout << result + (single * n);
  
  return 0;
}