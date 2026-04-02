#include <iostream>
#include <vector>

using namespace std;

int n;
bool visit[9] = {0,};
int arr[8];

void dfs(int selected){
  if(selected == n){
    for(int i =0;i<selected; i++) cout << arr[i] << " ";
    cout << '\n';
    return ;
  }
  
  for(int i =1;i<=n;i++){
    if(visit[i]) continue;
    arr[selected] = i;
    visit[i] = true;
    dfs(selected+1);
    visit[i] = false;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i =1; i<=n;i++){
    arr[0] = i;
    visit[i] = true;
    dfs(1);
    visit[i] = false;
  }
  
  return 0;
}