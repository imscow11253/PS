#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n,m,h;
int arr[100][100][100];
queue<tuple<int,int,int>> qu;
int cnt=0;
queue<int> cnt_qu;

void travel(){
    int row,col,ht, cnt;
    while(!qu.empty()){
        auto i = qu.front();
        qu.pop();
        //cout << qu.size() << '\n';
        
        row = get<1>(i);
        col = get<2>(i);
        ht = get<0>(i);
        cnt = cnt_qu.front();
        cnt_qu.pop();
        
        if(row-1>=0 && arr[ht][row-1][col]==0){
            arr[ht][row-1][col] =1;
            qu.push(make_tuple(ht, row-1, col));
            cnt_qu.push(cnt+1);
        }
        if(col-1>=0 && arr[ht][row][col-1]==0){
            arr[ht][row][col-1] =1;
            qu.push(make_tuple(ht, row, col-1));
            cnt_qu.push(cnt+1);
        }
        if(row+1<n && arr[ht][row+1][col]==0){
            arr[ht][row+1][col] =1;
            qu.push(make_tuple(ht, row+1, col));
            cnt_qu.push(cnt+1);
        }
        if(col+1<m && arr[ht][row][col+1] == 0){
            arr[ht][row][col+1] =1;
            qu.push(make_tuple(ht, row, col+1));
            cnt_qu.push(cnt+1);
        }
        if(ht+1<h && arr[ht+1][row][col] == 0){
            arr[ht+1][row][col] =1;
            qu.push(make_tuple(ht+1, row, col));
            cnt_qu.push(cnt+1);
        }
        if(ht-1>=0 && arr[ht-1][row][col] == 0){
            arr[ht-1][row][col] =1;
            qu.push(make_tuple(ht-1, row, col));
            cnt_qu.push(cnt+1);
        }
    }
    int check=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(arr[i][j][k] == 0) check=1;   
            }
        }
    }
    if(!check) cout << cnt;
    else cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> m >> n >> h;
    
    fill(&arr[0][0][0], &arr[99][99][99], 0);
    
    int temp, check=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k =0;k<m;k++){
                cin >> temp;
                arr[i][j][k] = temp;
                if(temp==1) {
                    qu.push(make_tuple(i,j,k));
                    cnt_qu.push(0);
                    check=1;
                }
            }
        }
    }    
    
    if(!check) cout << -1;
    else travel();
    
    return 0;
}