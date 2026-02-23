#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> vec(n);
  vector<int> origin(n);
  
  for(int i =0;i<n;i++){
    cin >> vec[i];
    origin[i] = vec[i];
  }
  
  sort(vec.begin(), vec.end());
  
  vector<bool> visit(n, false);
  for(int a : origin){
    for(int i =0;i<n;i++){
      if(a == vec[i] && !visit[i]){
        visit[i] = true;
        cout << i << " ";
        break;
      }
    }
  }
  
  return 0;
}