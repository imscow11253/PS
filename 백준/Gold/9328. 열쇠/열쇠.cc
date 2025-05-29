#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

int n,m;
string arr[100];
set<char> keys;
set<pair<int,int>> enterPoint;
set<pair<int,int>> alreadyGet;

bool isUpper(char a){
    return a >= 'A' && a <= 'Z';
}

int find_dollar(){
    int result=0;
    int check;
    
    queue<pair<int,int>> qu; //row,col;
    bool visit[100][100];
    do{
        check=0;
        memset(visit, false, sizeof(visit));
        while(!qu.empty()) qu.pop();
        
        for(auto a : enterPoint){
            qu.push(a);   
            visit[a.first][a.second] = true;
        }
        while(!qu.empty()){
            auto a = qu.front();
            qu.pop();
            
            int row = a.first;
            int col = a.second;
            
            // cout << row << " " << col << '\n';
            
            if(isUpper(arr[row][col]) && keys.find(arr[row][col] + 32) == keys.end()){
                continue;
            }
            if(arr[row][col] == '$' && alreadyGet.find({row,col}) == alreadyGet.end()) {
                result++;
                alreadyGet.insert({row,col});
            }
            if(arr[row][col] >= 'a' && arr[row][col] <= 'z' && alreadyGet.find({row,col}) == alreadyGet.end()){
                keys.insert(arr[row][col]);
                check=1;
                alreadyGet.insert({row,col});
            }
            
            if(row -1 >=0 && !visit[row-1][col] && arr[row-1][col] != '*'){
                qu.push({row-1,col});
                visit[row-1][col] = true;
            }
            if(row +1 < n && !visit[row+1][col] && arr[row+1][col] != '*'){
                qu.push({row+1,col});
                visit[row+1][col] = true;
            }
            if(col -1 >=0 && !visit[row][col-1] && arr[row][col-1] != '*'){
                qu.push({row,col-1});
                visit[row][col-1] = true;
            }
            if(col +1 < m && !visit[row][col+1] && arr[row][col+1] != '*'){
                qu.push({row,col+1});
                visit[row][col+1] = true;
            }
        }
    }while(check);
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        keys.clear();
        enterPoint.clear();
        alreadyGet.clear();
        
        for(int i =0;i<n;i++){
            cin >> arr[i];
            for(int j =0;j<m;j++){
                if(i != 0 && j != 0 && i != n-1 && j != m-1) continue;
                if(arr[i][j] != '*'){
                    enterPoint.insert({i,j});
                }
            }
        }
        string key_str;
        cin >> key_str;
        if(key_str != "0") for(char a : key_str) keys.insert(a);
        
        cout << find_dollar() << '\n'; 
    }
    
    return 0;
}