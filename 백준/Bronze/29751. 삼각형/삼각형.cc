#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a,b;
  cin >> a >> b;
  
  double t = a*b;
  cout << fixed << setprecision(1) << t / 2 << '\n';
  
  return 0;
}