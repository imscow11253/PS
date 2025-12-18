#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n;
  cin >> n;
  n %= 1500000;
  
  long long a,b;
  a = 0; b = 1;
  if(n == 0) cout << a;
  else if(n==1) cout << b;
  else {
    for(int i =2;i<=n; i++){
      long long temp = (a+b)%1000000;
      a=b;
      b=temp;
    }
    cout << b;
  }
  
  return 0;
}