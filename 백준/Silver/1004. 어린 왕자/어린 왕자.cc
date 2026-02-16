#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  int x1,y1,x2,y2;
  int n;
  while(t--){
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    int result=0;
    for(int i =0;i<n;i++){
      int x3,y3,r;
      cin >> x3 >> y3 >> r;
      bool check = false;
      if(pow(x3-x1, 2) + pow(y3-y1, 2) <= pow(r,2)) check ^= true;
      if(pow(x3-x2, 2) + pow(y3-y2, 2) <= pow(r,2)) check ^= true;
      if(check) result++;
    }
    cout << result << '\n';
  }
  
  return 0;
}