#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  if(n==1){
    cout << 4 << '\n'; return 0;
  }
  if(n==2){
    cout << 6 << '\n'; return 0;
  }
  
  long long fibo[81];
  fibo[1] =1;
  fibo[2] =1;
  long long result=6;
  for(int i =3;i<=n;i++){
    fibo[i] = fibo[i-1] + fibo[i-2];
    result -= fibo[i];
    result += fibo[i] * 3;
  }
  cout << result;
  
  return 0;
}