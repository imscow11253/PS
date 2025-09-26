#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int,int>> stk;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  int tp;
  for(int i =1;i<=n;i++){
    cin >> tp;
    if(stk.empty()){
      cout << 0 << " ";
      stk.push({tp, i});
    }
    else{
      if(stk.top().first > tp){
        cout << stk.top().second << " ";
        stk.push({tp, i});
      }
      else{
        int check=1;
        while(stk.top().first < tp){
          stk.pop();
          if(stk.empty()){
            cout << 0 << " ";
            stk.push({tp, i});
            check =0;
            break;
          }
        }
        if(check){
          cout << stk.top().second << " ";
          stk.push({tp, i});
        }
      }
    }
  }
  
  return 0;
}