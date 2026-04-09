#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  while(n--){
    string str;
    cin >> str;
    
    int length = str.length();
    int size = sqrt(length);
    
    vector<vector<char>> vec(size, vector<char>(size));
    int index=0;
    for(int i =0 ;i<size;i++){
      for(int j =0;j<size;j++){
        vec[i][j] = str[index++];
      }
    }
    
    for(int i =size-1; i>=0;i--){
      for(int j =0;j<size;j++){
        cout << vec[j][i];
      }
    }
    cout << '\n';
  }
  
  return 0;
}