#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  int arr[10001] = {0,};
  for(int i =1;i<=n;i++){
    int temp;
    cin >> temp;
    arr[i] = temp + arr[i-1];
  }
  
  // for(int i =1 ;i<=n;i++) cout << arr[i] << " " ; cout << '\n';
  
  int result=0;
  for(int i =0;i<=n;i++){
    for(int j =i+1;j<=n;j++){
      if(arr[j] - arr[i] == m) result++;
    }
  }
  
  cout << result;
  
  return 0;
}