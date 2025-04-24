#include <iostream>
#include <string>

using namespace std;

int n,m;
bool visit[600][600] = {0,};
string zido[600];
int result=0;

void dfs(int row, int col){
    visit[row][col] = true;
    if(zido[row][col] == 'P') result++;
    
    if(row -1 >=0 && !visit[row-1][col] && zido[row-1][col] != 'X') dfs(row-1, col);
    if(row +1 < n && !visit[row+1][col] && zido[row+1][col] != 'X') dfs(row+1, col);
    if(col -1 >=0 && !visit[row][col-1] && zido[row][col-1] != 'X') dfs(row, col-1);
    if(col +1 < m && !visit[row][col+1] && zido[row][col+1] != 'X') dfs(row, col+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        cin >> zido[i];
    }
    
    int row,col;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(zido[i][j] == 'I'){
                row = i;
                col = j;
            }
        }
    }
    
    dfs(row, col);
    if(result ==0) cout << "TT";
    else cout << result;
    
    return 0;
}