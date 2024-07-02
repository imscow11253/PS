#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n,m;
int arr[1000][1000] = {0,};
queue<tuple<int,int,int>> qu;
int cnt=0;

void travel(){
    int row,col, cnt;
    while(!qu.empty()){
        auto i = qu.front();
        qu.pop();
        //cout << qu.size() << '\n';
        
        row = get<0>(i);
        col = get<1>(i);
        cnt = get<2>(i);
        
        if(row-1>=0 && arr[row-1][col]==0){
            arr[row-1][col] =1;
            qu.push(make_tuple(row-1, col, cnt+1));
        }
        if(col-1>=0 && arr[row][col-1]==0){
            arr[row][col-1] =1;
            qu.push(make_tuple(row, col-1, cnt+1));
        }
        if(row+1<n && arr[row+1][col]==0){
            arr[row+1][col] =1;
            qu.push(make_tuple(row+1, col, cnt+1));
        }
        if(col+1<m && arr[row][col+1] == 0){
            arr[row][col+1] =1;
            qu.push(make_tuple(row, col+1, cnt+1));
        }
    }
    int check=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout << arr[i][j] << " ";
            if(arr[i][j] == 0) check=1;
        }//cout << '\n';
    }
    if(!check) cout << cnt;
    else cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n;
    
    int temp, check=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> temp;
            arr[i][j] = temp;
            if(temp==1) {
                qu.push(make_tuple(i,j,0));
                check=1;
            }
        }
    }    
    
    if(!check) cout << -1;
    else travel();
    
    return 0;
}