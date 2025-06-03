#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n,m,t;
int arr[50][50];
vector<int> cleaner;
vector<tuple<int, int,int>> dust; //row, col, amount

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> t;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == -1) cleaner.push_back(i);
            else if(arr[i][j] != 0) dust.push_back(make_tuple(i,j,arr[i][j]));
        }
    }
    
    while(t--){
        //미세먼지 확산
        for(auto a : dust){
            int row = get<0>(a);
            int col = get<1>(a);
            int amount = get<2>(a);
            
            if(row -1 >=0 && arr[row-1][col] != -1){
                arr[row-1][col] += amount /5;
                arr[row][col] -= amount /5;
            }
            if(row +1 < n && arr[row+1][col] != -1){
                arr[row+1][col] += amount /5;
                arr[row][col] -= amount /5;
            }
            if(col -1 >=0 && arr[row][col-1] != -1){
                arr[row][col-1] += amount /5;
                arr[row][col] -= amount /5;
            }
            if(col + 1 < m && arr[row][col+1] != -1){
                arr[row][col+1] += amount /5;
                arr[row][col] -= amount /5;
            }
        }
        
        //공기청정 위 순환
        for(int i = cleaner[0]+1; i>=0;i--){
            if(arr[i][0] != 0){
                if(i+1 != cleaner[0]){
                    arr[i+1][0] = arr[i][0];
                }
                arr[i][0] =0;
            }
        }
        for(int i =1;i<m;i++){
            if(arr[0][i] != 0){
                arr[0][i-1] = arr[0][i];
                arr[0][i] =0;
            }
        }
        for(int i =1;i<=cleaner[0];i++){
            if(arr[i][m-1] != 0){
                arr[i-1][m-1] = arr[i][m-1];
                arr[i][m-1] =0;
            }
        }
        for(int i = m-2;i>0;i--){
            if(arr[cleaner[0]][i] != 0){
                arr[cleaner[0]][i+1] = arr[cleaner[0]][i];
                arr[cleaner[0]][i] =0;
            }
        }
        //공기청정 아래 순환
        for(int i = cleaner[1]+1; i<n;i++){
            if(arr[i][0] != 0){
                if(i-1 != cleaner[0]){
                    arr[i-1][0] = arr[i][0];
                }
                arr[i][0] =0;
            }
        }
        for(int i =1;i<m;i++){
            if(arr[n-1][i] != 0){
                arr[n-1][i-1] = arr[n-1][i];
                arr[n-1][i] =0;
            }
        }
        for(int i =n-2;i>=cleaner[1];i--){
            if(arr[i][m-1] != 0){
                arr[i+1][m-1] = arr[i][m-1];
                arr[i][m-1] =0;
            }
        }
        for(int i = m-2;i>0;i--){
            if(arr[cleaner[1]][i] != 0){
                arr[cleaner[1]][i+1] = arr[cleaner[1]][i];
                arr[cleaner[1]][i] =0;
            }
        }
        
        dust.clear();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(arr[i][j] != 0 && arr[i][j] != -1) dust.push_back(make_tuple(i,j,arr[i][j]));
            }
        }
        
        // cout << "=======================\n";
        // for(int i =0;i<n;i++){
        //     for(int j =0;j<m;j++){
        //         cout << arr[i][j] << " ";
        //     }cout << '\n';
        // }
    }
    
    int sum =0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j] != -1) sum += arr[i][j];
        }
    }
    
    cout << sum;
    
    return 0;
}