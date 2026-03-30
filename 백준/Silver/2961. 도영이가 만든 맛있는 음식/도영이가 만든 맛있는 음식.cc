#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <climits>

using namespace std;

int n;
pair<int,int> arr[10];
int result=INT_MAX;

void dfs(int num, int index, int sour, int bitter){
  if(n-index < num) return ;
  if(num == 0){
    result = min(result, abs(sour - bitter));
    return ;
  }
  
  for(int i =index; i<=n;i++){
    dfs(num-1, i+1, sour * arr[i].first, bitter + arr[i].second);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =0;i<n;i++){
    int a,b;
    cin >>a >> b;
    arr[i] = {a,b};
  }
  
  for(int i =1;i<=n;i++){
    dfs(i,0, 1, 0);
  }
  cout << result;
  
  return 0;
}