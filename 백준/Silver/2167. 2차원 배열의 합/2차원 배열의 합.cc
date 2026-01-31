#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;
  int arr[301][301] = {0,};
  for(int i =1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> arr[i][j];
    }
  }
  
  int sum[301][301] = {0,};
  for(int i =1;i<=m;i++){
    for(int j =1;j<=n;j++){
      sum[j][i] = sum[j-1][i] + arr[j][i];
    }
  }
  
  int k;
  cin >> k;
  
  while(k--){
    int x,y; int z,r;
    cin >> x >> y >> z >> r;
    int result =0;
    for(int i = y; i<=r ; i++){
      result += (sum[z][i] - sum[x-1][i]);
    }
    
    cout << result << '\n';    
  }

  return 0;
}