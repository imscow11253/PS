#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n,m;
string arr[20];
bool visit[20][20] = {0,};
bool alphabet[26] = {0,};
int result =0;

void dfs(int row, int col, int value){
    visit[row][col] = true;
    alphabet[arr[row][col] - 'A'] = true;
    // cout << arr[row][col] << '\n';
    
    result = max(result, value);
    
    if(row-1 >=0 && !visit[row-1][col] && !alphabet[arr[row-1][col] - 'A']){
        dfs(row-1, col, value+1);
        visit[row-1][col] = false;
        alphabet[arr[row-1][col] - 'A'] = false;
    }
    if(row+1 < n && !visit[row+1][col] && !alphabet[arr[row+1][col] - 'A']){
        dfs(row+1, col, value+1);
        visit[row+1][col] = false;
        alphabet[arr[row+1][col] - 'A'] = false;
    }
    if(col -1 >=0 && !visit[row][col-1] && !alphabet[arr[row][col-1] - 'A']){
        dfs(row, col-1, value+1);
        visit[row][col-1] = false;
        alphabet[arr[row][col-1] - 'A'] = false;
    }
    if(col+1 <m && !visit[row][col+1] && !alphabet[arr[row][col+1] - 'A']){
        dfs(row, col+1, value+1);
        visit[row][col+1] = false;
        alphabet[arr[row][col+1] - 'A'] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    
    dfs(0,0,1);
    cout << result;
    
    return 0;
}