#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,k;
  cin >> n >> k;
  
  bool arr[1001] = {0,};
  int index=0;
  for(int i =2;i<=n;i++){
    if(arr[i]) continue;
    int value = i+i;
    index++;
    if(index == k){
      cout << i << '\n';
      return 0;
    }
    while(value <= n){
      if(arr[value]){
        value += i;
        continue;
      }
      arr[value] = true;
      index++;
      if(index == k){
        cout << value << '\n';
        return 0;
      }
      value += i;
    }
  }
  
  return 0;
}