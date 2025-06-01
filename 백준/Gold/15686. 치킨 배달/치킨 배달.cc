#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <set>
#include <climits>

using namespace std;

int n,m;
int arr[50][50];
vector<pair<int,int>> chickens;
vector<pair<int,int>> zip;
vector<int> selected;
int result=INT_MAX;

// int bfs(int r, int c){
//     queue<pair<int,int>> qu;
//     bool visit[50][50] = {0,};
    
//     qu.push({r,c});
//     visit[r][c] = true;
    
//     while(!qu.empty()){
//         auto a = qu.front();
//         qu.pop();
        
//         int row = a.first;
//         int col = a.second;
        
//         if(selectedChickens.find({row, col}) != selectedChickens.end()) {
//             return abs(row - r) + abs(col - c);
//         }
        
//         if(row-1>=0 && !visit[row-1][col]){
//             qu.push({row-1, col});
//             visit[row-1][col] = true;
//         }
//         if(row+1<n && !visit[row+1][col]){
//             qu.push({row+1, col});
//             visit[row+1][col] = true;
//         }
//         if(col-1>=0 && !visit[row][col-1]){
//             qu.push({row, col-1});
//             visit[row][col-1] = true;
//         }
//         if(col+1<n && !visit[row][col+1]){
//             qu.push({row, col+1});
//             visit[row][col+1] = true;
//         }
//     }
//     return 0;
// }

void calculateDistance() {
    int value = 0;
    for (auto& house : zip) {
        int min_dist = INT_MAX;
        for (auto idx : selected) {
            auto& chicken = chickens[idx];
            min_dist = min(min_dist, abs(house.first - chicken.first) + abs(house.second - chicken.second));
        }
        value += min_dist;
    }
    result = min(result, value);
}

void dfs(int idx, int cnt) {
    if (cnt == m) {
        calculateDistance();
        return;
    }
    for (int i = idx; i < chickens.size(); i++) {
        selected.push_back(i);
        dfs(i + 1, cnt + 1);
        selected.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) zip.push_back({i,j});
            if(arr[i][j] == 2) chickens.push_back({i,j});
        }
    }
    
    dfs(0,0);
    cout << result;
    
    return 0;
}