#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

int n,m,k;
int arr[500][500] = {{0,}};
int visit[500][500] = {{0,}};
int result=0;

queue<pair<int,int>> qu;

void travel(){
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int row = a.first;
        int col = a.second;
        
        if(row-1 >=0 && visit[row-1][col] ==0 && abs(arr[row][col]-arr[row-1][col]) <= k){
            visit[row-1][col] =1;
            qu.push({row-1, col});
        }
        if(col-1 >=0 && visit[row][col-1] ==0 && abs(arr[row][col]-arr[row][col-1]) <= k){
            visit[row][col-1] =1;
            qu.push({row, col-1});
        }
        if(row+1 <n && visit[row+1][col] ==0 && abs(arr[row][col]-arr[row+1][col]) <= k){
            visit[row+1][col] =1;
            qu.push({row+1, col});
        }
        if(col+1 <m && visit[row][col+1] ==0 && abs(arr[row][col]-arr[row][col+1]) <= k){
            visit[row][col+1] =1;
            qu.push({row, col+1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt=0;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j] ==0 ) {
                qu.push({i,j});
                visit[i][j] =1;
                travel();
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}