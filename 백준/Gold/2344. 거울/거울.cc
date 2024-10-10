#include <iostream>

using namespace std;

int n,m;
int map[1002][1002]={0,};
int result[4001] = {};

void simul(){
    for(int i=1;i<=n;i++){
        int col =1;
        int row =i;
        bool is_row;
        if(map[row][col]) is_row = false;
        else is_row = true;
        while(row >= 1 && col <= m){
            // cout << row << " " << col << '\n';
            if(is_row){
                if(map[row][col+1]){
                    is_row=false;
                }
                col++;
            }
            else{
                if(map[row-1][col]){
                    is_row=true;
                }
                row--;
            }
        }
        if(row == 0) {
            result[i] = 2*(n+m) - col + 1;
            result[2*(n+m) - col + 1] = i;
        }
        else {
            result[i] = n+m+n - row +1;
            result[n+m+n - row +1] = i;
        }
        // cout << "result : " << i << " " << result[i] << '\n';
    }
    for(int j=1;j<=m;j++){
        int col =j;
        int row =n;
        bool is_col;
        if(map[row][col]) is_col = false;
        else is_col = true;
        while(row >= 1 && col <= m){
            // cout << row << " " << col << '\n';
            if(is_col){
                if(map[row-1][col]){
                    is_col=false;
                }
                row--;
            }
            else{
                if(map[row][col+1]){
                    is_col=true;
                }
                col++;
            }
        }
        if(row == 0) {
            result[j+n] = 2*(n+m) - col + 1;
            result[2*(n+m) - col + 1] = j+n;
        }
        else {
            result[j+n] = n+m+n - row +1;
            result[n+m+n - row +1] = j+n;
        }
        // cout << "result : " << j+n << " " << result[j+n] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> map[i][j];
        }
    }
    
    simul();
    
    for(int i=1;i<=2*(n+m);i++){
        cout << result[i] << " ";
    }
    
    return 0;
    
}