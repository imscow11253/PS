#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int arr[8][8];
vector<pair<int,int>> zero;
vector<pair<int,int>> virus;
int result=0;

void bfs(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    queue<pair<int,int>> qu;
    bool visit[8][8] = {0,};
    
    for(auto p : virus) qu.push(p);
    int cnt=0;
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        
        int row = p.first;
        int col = p.second;
        
        // cout << row << " " << col << '\n';
        
        if(p == a || p == b || p == c) continue;
        
        if(arr[row][col] == 0){
            cnt++;
        } 
        
        if(row-1 >= 0 && !visit[row-1][col] && arr[row-1][col] == 0){
            qu.push({row-1,col});
            visit[row-1][col] = true;
        }
        if(row+1 < n && !visit[row+1][col] && arr[row+1][col] == 0){
            qu.push({row+1,col});
            visit[row+1][col] = true;
        }
        if(col-1 >= 0 && !visit[row][col-1] && arr[row][col-1] == 0){
            qu.push({row,col-1});
            visit[row][col-1] = true;
        }
        if(col +1 <m && !visit[row][col+1] && arr[row][col+1] == 0){
            qu.push({row,col+1});
            visit[row][col+1] = true;
        }
    }
    int size = zero.size()-3-cnt;
    result = max(result, size);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) zero.push_back({i,j});
            if(arr[i][j] == 2) virus.push_back({i,j});
        }
    }
    
    for(int i =0;i<zero.size()-2;i++){
        for(int j=i+1;j<zero.size()-1;j++){
            for(int k=j+1;k<zero.size();k++){
                // cout << "===========\n";
                // cout << zero[i].first  << " " << zero[i].second << "\n";
                // cout << zero[j].first  << " " << zero[j].second << "\n";
                // cout << zero[k].first  << " " << zero[k].second << "\n";
                // cout << "===========\n";
                bfs(zero[i], zero[j], zero[k]);
            }
        }
    }
    
    cout << result;
    
    return 0;
}