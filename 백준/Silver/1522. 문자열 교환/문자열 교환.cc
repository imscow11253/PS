#include <iostream>
#include <string>

using namespace std;

string str;
int window_size=0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> str;
  for(char a : str){
    if(a == 'b') window_size++;
  }
  
  if(window_size ==0 || window_size == str.length()){
    cout << 0; return 0;
  }
  
  int b_cnt =0;
  for(int i =0;i<window_size; i++){
    if(str[i] == 'b') b_cnt++;
  }
  
  // cout <<"0: " << b_cnt << '\n';
  int result = window_size-b_cnt;
  int index=0;
  for(int i =1;i<str.length();i++){
    if(i-1 + window_size >= str.length()){
      if(str[i-1] == 'b') b_cnt--;
      if(str[index] == 'b') b_cnt++;
      index++;
      result = min(result, window_size-b_cnt);
    }
    else{
      if(str[i-1] == 'b') b_cnt--;
      if(str[i-1+window_size] == 'b') b_cnt++;
      result = min(result, window_size-b_cnt);
    }
    // cout << i << ": " << b_cnt << '\n';
  }
  cout << result;
  
  return 0;
}