#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100001];
int result=0;
bool visit[100001] = {0,};

void bfs(int sta){
  queue<int> qu;
  qu.push(sta);
  visit[sta] = true;
  
  while(!qu.empty()){
    int position = qu.front();
    qu.pop();
    
    result++;
    
    if(position + arr[position] <= n && !visit[position + arr[position]]){
      visit[position + arr[position]] = true; 
      qu.push(position + arr[position]);
    }
    if(position - arr[position] > 0 && !visit[position - arr[position]]){
      visit[position - arr[position]] = true;
      qu.push(position - arr[position]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =1;i<=n;i++){
    cin >> arr[i];
  }
  
  int s;
  cin >> s;
  bfs(s);

  cout << result;
  
  return 0;
}