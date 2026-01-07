#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<int> graph[2000];
bool visit[2000] = {0,};

void dfs(int sta, int num){
  if(num == 5){
    cout << 1; exit(0);
  }
  visit[sta] = true;
  
  for(const int a : graph[sta]){
    if(visit[a]) continue;
    dfs(a, num+1);
    visit[a] = false;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  int sta, en;
  while(m--){
    cin >> sta >> en;
    graph[sta].push_back(en);
    graph[en].push_back(sta);
  }
  
  for(int i =0;i<n;i++){
    dfs(i,1);
    visit[i] = false;
  }
  cout << 0;
  
  return 0;
}