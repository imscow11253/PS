#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

short t;
short n;
short row,col;
short d_row, d_col;

queue<short> r_qu;
queue<short> c_qu;
queue<short> cnt_qu;
short visit[300][300] = {0,};

void travel(){
    while(!r_qu.empty()){
        
        short r = r_qu.front();
        short c = c_qu.front();
        short cnt = cnt_qu.front();
        r_qu.pop();
        c_qu.pop();
        cnt_qu.pop();
        
        if(r == d_row && c == d_col){
            cout << cnt << '\n';
            break;
        }
        
        // visit[r][c] =1;
        
        if(!visit[r-2][c-1] && r-2 >= 0 && c-1 >= 0){
            visit[r-2][c-1] =1;
            r_qu.push(r-2);
            c_qu.push(c-1);
            cnt_qu.push(cnt+1);
        }
        if(!visit[r-2][c+1] && r-2 >= 0 && c+1 < n){
            visit[r-2][c+1] =1;
            r_qu.push(r-2);
            c_qu.push(c+1);
            cnt_qu.push(cnt+1);
        }
        if(!visit[r-1][c-2] && r-1 >= 0 && c-2 >= 0){
            visit[r-1][c-2] =1;
            r_qu.push(r-1);
            c_qu.push(c-2);
            cnt_qu.push(cnt+1);
        }
        if(!visit[r-1][c+2] && r-1 >= 0 && c+2 < n){
            visit[r-1][c+2] =1;
            r_qu.push(r-1);
            c_qu.push(c+2);
            cnt_qu.push(cnt+1);
        }
        
        if(!visit[r+2][c-1] && r+2 < n && c-1 >= 0){
            visit[r+2][c-1] =1;
            r_qu.push(r+2);
            c_qu.push(c-1);
            cnt_qu.push(cnt+1);
        }
        if(!visit[r+2][c+1] && r+2 < n && c+1 < n){
            visit[r+2][c+1] =1;
            r_qu.push(r+2);
            c_qu.push(c+1);
            cnt_qu.push(cnt+1);
        }
        if(!visit[r+1][c-2] && r+1 < n && c-2 >= 0){
            visit[r+1][c-2] =1;
            r_qu.push(r+1);
            c_qu.push(c-2);
            cnt_qu.push(cnt+1);
        }
        if(!visit[r+1][c+2] && r+1 < n && c+2 < n){
            visit[r+1][c+2] =1;
            r_qu.push(r+1);
            c_qu.push(c+2);
            cnt_qu.push(cnt+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    while(t--){
        cin >> n;
        cin >> row >> col;
        cin >> d_row >> d_col;
        
        r_qu.push(row);
        c_qu.push(col);
        cnt_qu.push(0);
        visit[row][col] =1;
        travel();
        
        memset(visit, 0, sizeof(visit));
        while(!r_qu.empty()){
            r_qu.pop();
            c_qu.pop();
            cnt_qu.pop();
        }
    }
    
    return 0;
}
