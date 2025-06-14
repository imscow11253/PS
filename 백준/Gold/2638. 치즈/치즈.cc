#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
vector<pair<int,int>> cheese;
int arr[100][100] = {0,};
bool visit[100][100] = {0,};

void bfs(int r, int c){
    queue<pair<int,int>> qu;
    
    qu.push({r,c});
    visit[r][c] = true;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int row = a.first;
        int col = a.second;
        
        // cout << row << " " << col<< '\n';
        
        arr[row][col] = 2;
        
        if(row-1>=0 && !visit[row-1][col] && arr[row-1][col] == 0){
            qu.push({row-1,col});
            visit[row-1][col] = true;
        }
        if(row+1<n && !visit[row+1][col] && arr[row+1][col] == 0){
            qu.push({row+1,col});
            visit[row+1][col] = true;
        }
        if(col-1>=0 && !visit[row][col-1] && arr[row][col-1] == 0){
            qu.push({row,col-1});
            visit[row][col-1] = true;
        }
        if(col+1 < m && !visit[row][col+1] && arr[row][col+1] == 0){
            qu.push({row,col+1});
            visit[row][col+1] = true;
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
            if(arr[i][j] == 1) cheese.push_back({i,j});
        }
    }
    
    bfs(0,0);
    
    int cnt=0;
    while(cheese.size() != 0){
        cnt++;
        vector<pair<int,int>> new_cheese;
        vector<pair<int,int>> delete_cheese;
        for(auto a : cheese){
            int check=0;
            int row = a.first;
            int col = a.second;
            
            if(row -1 >=0 && arr[row-1][col] == 2) check++;
            if(row +1 <n && arr[row+1][col] == 2) check++;
            if(col -1 >=0 && arr[row][col-1] == 2) check++;
            if(col +1 <m && arr[row][col+1] == 2) check++;
            
            if(check >= 2){
                delete_cheese.push_back(a);
            }
            else{
                new_cheese.push_back(a);
            }
        }
        for(auto a : delete_cheese) bfs(a.first, a.second);
        cheese = new_cheese;   
    }
    
    cout << cnt;
    
    return 0;
}