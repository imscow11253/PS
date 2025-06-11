#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>

using namespace std;

int n,m;
int arr[1000][1000];
vector<pair<int,int>> zero;
vector<pair<int,int>> one;
pair<int,int> blockNum[1000][1000]; //id, num
bool visit[1000][1000] = {0,};
int id=1;

void bfs(int r, int c){
    queue<pair<int,int>> qu;
    vector<pair<int,int>> st;
    int num=0;
    
    qu.push({r,c});
    visit[r][c] = true;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int row = a.first;
        int col = a.second;
        
        num++;
        st.push_back({row,col});
        
        if(row -1 >=0 && !visit[row-1][col] && arr[row-1][col] == 0){
            visit[row-1][col] = true;
            qu.push({row-1, col});
        }
        if(row +1 < n && !visit[row+1][col] && arr[row+1][col] == 0){
            visit[row+1][col] = true;
            qu.push({row+1, col});
        }
        if(col -1 >=0 && !visit[row][col-1] && arr[row][col-1] == 0){
            visit[row][col-1] = true;
            qu.push({row, col-1});
        }
        if(col +1 < m && !visit[row][col+1] && arr[row][col+1] == 0){
            visit[row][col+1] = true;
            qu.push({row, col+1});
        }
    }
    
    for(auto a : st){
        blockNum[a.first][a.second] = {id, num};
    }
    id++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        string str;
        cin >> str;
        for(int j =0;j<m;j++){
            char ch = str[j];
            arr[i][j] = ch -'0';
            if(arr[i][j] == 0) zero.push_back({i,j});
            else one.push_back({i,j});
        }
    }
    
    for(auto a : zero){
        if(!visit[a.first][a.second]) bfs(a.first, a.second);
    }
    
    int result[1000][1000] = {0,};
    set<int> ids;
    for(auto a : one){
        ids.clear();
        
        int row = a.first;
        int col = a.second;
        
        int value =1;
        if(row-1 >= 0 && ids.find(blockNum[row-1][col].first) == ids.end()){
            value += blockNum[row-1][col].second;
            ids.insert(blockNum[row-1][col].first);
        }
        if(row+1 < n && ids.find(blockNum[row+1][col].first) == ids.end()){
            value += blockNum[row+1][col].second;
            ids.insert(blockNum[row+1][col].first);
        }
        if(col -1 >= 0 && ids.find(blockNum[row][col-1].first) == ids.end()){
            value += blockNum[row][col-1].second;
            ids.insert(blockNum[row][col-1].first);
        }
        if(col + 1 < m && ids.find(blockNum[row][col+1].first) == ids.end()){
            value += blockNum[row][col+1].second;
            ids.insert(blockNum[row][col+1].first);
        }
        
        result[row][col] = value%10;
    }
    
    // for(int i =0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         cout << blockNum[i][j].second;
    //     }cout << '\n';
    // }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cout << result[i][j];
        }cout << '\n';
    }
    
    return 0;
}