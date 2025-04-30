#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[500][500];
int max_value =0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            int row = i;
            int col = j;
            if(col + 3 < m){
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i][j+2]+ arr[i][j+3]);
            }
            if(row + 3 < n){
                max_value = max(max_value, arr[i][j] + arr[i+1][j]+ arr[i+2][j]+ arr[i+3][j]);
            }
            if(row+1 < n && col +1 < m){
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i+1][j]+ arr[i+1][j+1]);
            }
            if(row + 2 <n && col +1 < m){
                max_value = max(max_value, arr[i][j] + arr[i+1][j]+ arr[i+2][j]+ arr[i+2][j+1]);
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i+1][j+1]+ arr[i+2][j+1]);
                max_value = max(max_value, arr[i][j] + arr[i+1][j]+ arr[i+1][j+1]+ arr[i+2][j+1]);
                max_value = max(max_value, arr[i][j] + arr[i+1][j]+ arr[i+1][j+1]+ arr[i+2][j]);
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i+1][j]+ arr[i+2][j]);
            }
            if(row +1 < n && col +2 < m){
                max_value = max(max_value, arr[i][j] + arr[i+1][j]+ arr[i][j+1]+ arr[i][j+2]);
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i][j+2]+ arr[i+1][j+1]);
                max_value = max(max_value, arr[i][j] + arr[i+1][j]+ arr[i+1][j+1]+ arr[i+1][j+2]);
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i][j+2]+ arr[i+1][j+2]);
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i+1][j+1]+ arr[i+1][j+2]);
            }
            if(row -1 >=0 && col +2 < m){
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i][j+2]+ arr[i-1][j+2]);
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i-1][j+1]+ arr[i-1][j+2]);
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i-1][j+1]+ arr[i][j+2]);
            }
            if(row -1 >=0 && row +1 <n && col + 1 < m){
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i-1][j+1]+ arr[i+1][j+1]);
            }
            if(row +2 < n && col -1 >=0){
                max_value = max(max_value, arr[i][j] + arr[i+1][j]+ arr[i+1][j-1]+ arr[i+2][j-1]);
            }
            if(row -2 >=0 && col + 1 < m){
                max_value = max(max_value, arr[i][j] + arr[i][j+1]+ arr[i-1][j+1]+ arr[i-2][j+1]);
            }
        }
    }
    
    cout << max_value;

    
    return 0;
}