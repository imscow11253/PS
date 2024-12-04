#include <iostream>

using namespace std;

int n,m,k;
int arr[2501][2501] = {0,};
int row_sum[2501][2501] = {0,};
int col_sum[2501][2501] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            row_sum[i][j] = arr[i][j] + row_sum[i][j-1];
            col_sum[i][j] = arr[i][j] + col_sum[i-1][j];
        }
    }
    
    int result =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i <= k || j <= k) continue;
            if(i+k > n || j+k > m) continue;
            if(k==0) {
                if(arr[i][j] == 1) result++;
                continue;
            }
            if(row_sum[i][j+k] - row_sum[i][j-k-1] + col_sum[i+k][j] - col_sum[i-k-1][j] -1 == 4*k+1) {
                result++;
                // cout << i << " " << j << '\n';
            }
        }
    }
    cout << result;
    
    return 0;
}