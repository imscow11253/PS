#include <iostream>
#include <deque>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  deque<int> dq;
  for(int i =1;i<=n;i++){
    dq.push_back(i);
  }
  
  while(dq.size() > 1){
    cout << dq.front() << " ";
    dq.pop_front();
    
    dq.push_back(dq.front());
    dq.pop_front();
  }
  cout << dq.front();
  
  return 0;
}