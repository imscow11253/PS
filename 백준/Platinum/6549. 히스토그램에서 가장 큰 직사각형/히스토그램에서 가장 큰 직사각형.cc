#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while(cin >> n && n){
    vector<int> arr(n);
    for(int i =0;i<n;i++) cin >> arr[i];
    
    stack<pair<int,int>> stk; //height, start Index
    long long result =0;
    
    for(int i =0;i<n;i++){
      int start =i;
      if(stk.empty()){
        stk.push({arr[i], i});
        continue;
      }
      
      while(!stk.empty() && stk.top().first > arr[i]){
        auto p = stk.top();
        stk.pop();
        
        int height = p.first;
        int index = p.second;
        
        long long temp = height * (long long)(i-index);
        result = max(result, temp);       
        start = index;
      }
      stk.push({arr[i], start});
    }
    
    while(!stk.empty()){
      auto p = stk.top();
      stk.pop();
      
      int height = p.first;
      int index = p.second;
      
      long long temp = height * (long long)(n-index);
      result = max(result, temp);
    }
    
    cout << result <<'\n';
  }

  
  return 0;
}