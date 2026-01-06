#include <iostream>
#include <deque>

using namespace std;

int arr[100000];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  for(int i =0;i<n;i++){
    cin >> arr[i];
  }
  
  deque<int> dq;
  int temp;
  for(int i =0;i<n;i++){
    cin >> temp;
    if(arr[i]) continue;
    dq.push_front(temp);
  }
  
  int m;
  cin >> m;
  
  while(m--){
    cin >> temp;
    dq.push_back(temp);
    cout << dq.front() << " ";
    dq.pop_front();
  }
  
  
  return 0;
}