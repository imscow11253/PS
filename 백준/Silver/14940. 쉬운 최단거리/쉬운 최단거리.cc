#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n,m;
int arr[1000][1000];
int target_row, target_col;
int result[1000][1000] = {0,};
bool visit[1000][1000] = {0,};

void bfs(){
    queue<tuple<int,int,int>> qu;
    qu.push(make_tuple(target_row,target_col, 0));
    visit[target_row][target_col] = true;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int row = get<0>(a);
        int col = get<1>(a);
        int distance = get<2>(a);
        
        result[row][col] = distance;
        
        if(row -1 >=0 && !visit[row-1][col] && arr[row-1][col] != 0){
            visit[row-1][col] = true;
            qu.push(make_tuple(row-1 ,col, distance+1));
        }
        if(row +1 <n && !visit[row+1][col] && arr[row+1][col] != 0){
            visit[row+1][col] = true;
            qu.push(make_tuple(row+1 ,col, distance+1));
        }
         if(col -1 >=0 && !visit[row][col-1] && arr[row][col-1] != 0){
            visit[row][col-1] = true;
            qu.push(make_tuple(row ,col-1, distance+1));
        }
         if(col +1 < m && !visit[row][col+1] && arr[row][col+1] != 0){
            visit[row][col+1] = true;
            qu.push(make_tuple(row ,col+1, distance+1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                target_row = i;
                target_col = j;
            }
        }
    }
    
    bfs();
    
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j] == 1 && result[i][j] == 0) cout << -1 << " ";
            else cout << result[i][j] << " ";
        }cout << '\n';
    }
    
    return 0;
}