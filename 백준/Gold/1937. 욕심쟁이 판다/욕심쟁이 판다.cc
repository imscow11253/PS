#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[500][500];
int dp[500][500] = {0,};

int dfs(int row, int col){
    if(dp[row][col] != 0) return dp[row][col];
    
    int result = 1;
    if(row-1 >=0 && arr[row-1][col] > arr[row][col]){
        result = max(result, dfs(row-1, col)+1);
    }
    if(row+1 < n && arr[row+1][col] > arr[row][col]){
        result = max(result, dfs(row+1, col)+1);
    }
    if(col-1 >=0 && arr[row][col-1] > arr[row][col]){
        result = max(result, dfs(row, col-1)+1);
    }
    if(col+1 < n && arr[row][col+1] > arr[row][col]){
        result = max(result, dfs(row, col+1)+1);
    }
    dp[row][col] = result;
    return dp[row][col];
}

void all_bfs(){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            dfs(i,j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    all_bfs();

    int result =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            // cout << dp[i][j] << " ";
            result = max(result, dp[i][j]);
        }
        // cout << '\n';
    }
    
    cout << result;
    
    return 0;
}