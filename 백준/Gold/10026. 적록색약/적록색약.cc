#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
string arr[100];
bool visit[100][100] = {0,};

bool check_same_color(int row, int col, char color, bool isSaekYack){
    if(color == 'B' && arr[row][col] == 'B') return true; 
    if(color == 'R' && arr[row][col] == 'R') return true; 
    if(color == 'G' && arr[row][col] == 'G') return true; 
    if(isSaekYack){
        if(color == 'R' && arr[row][col] == 'G') return true;
        if(color == 'G' && arr[row][col] == 'R') return true;
    }
    return false;
}

void dfs(int row, int col, char color, bool isSaekYack){
    if(row-1 >=0 && !visit[row-1][col] && check_same_color(row-1, col, color, isSaekYack)){
        visit[row-1][col] = true;
        dfs(row-1, col, arr[row-1][col], isSaekYack);
    }
     if(row+1 <n && !visit[row+1][col] &&check_same_color(row+1, col, color, isSaekYack)){
        visit[row+1][col] = true;
        dfs(row+1, col, arr[row+1][col], isSaekYack);
    }
     if(col-1 >=0 && !visit[row][col-1] && check_same_color(row, col-1, color, isSaekYack)){
        visit[row][col-1] = true;
        dfs(row, col-1, arr[row][col-1], isSaekYack);
    }
     if(col+1 < n && !visit[row][col+1] && check_same_color(row, col+1, color, isSaekYack)){
        visit[row][col+1] = true;
        dfs(row, col+1, arr[row][col+1], isSaekYack);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]) continue;
            visit[i][j] = true;
            dfs(i,j, arr[i][j], false);
            result++;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = false;
        }
    }
    
    int result2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]) continue;
            visit[i][j] = true;
            dfs(i,j, arr[i][j], true);
            result2++;
        }
    }
    
    cout << result << " " << result2;
    
    
    return 0;
}