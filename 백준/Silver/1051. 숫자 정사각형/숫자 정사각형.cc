#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  
  char arr[50][50];
  for(int i =0;i<n;i++){
    string str;
    cin >> str;
    for(int j =0;j<m;j++){
      char a = str[j];
      arr[i][j] = a;
    }
  }
  
  int size = min(n,m);
  int result=0;
  for(int k =0;k<size;k++){
    for(int i =0;i<n;i++){
      if(i + k >= n) break;
      for(int j =0;j<m;j++){
        if(j + k >= m) break;
        char index = arr[i][j];
        if(arr[i+k][j] != index) continue;
        if(arr[i][j+k] != index) continue;
        if(arr[i+k][j+k] != index) continue;
        result = max(result, (k+1)*(k+1));
      }
    }
  }
  
  cout << result;

  return 0;
}