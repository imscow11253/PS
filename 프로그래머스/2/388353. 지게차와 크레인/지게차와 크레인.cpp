#include <string>
#include <vector>
#include <iostream>

using namespace std;

string map[52][52];

void dfs(int row, int col){
    if(map[row+1][col] == "a"){
        map[row+1][col] = "\n";
        dfs(row+1, col);
    }
    if(map[row-1][col] == "a"){
        map[row-1][col] = "\n";
        dfs(row-1, col);
    }
    if(map[row][col+1] == "a"){
        map[row][col+1] = "\n";
        dfs(row, col+1);
    }
    if(map[row][col-1] == "a"){
        map[row][col-1] = "\n";
        dfs(row, col-1);
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int n = storage.size();
    int m = storage[0].length();
    
    for(int i =0;i<52;i++){
        for(int j =0;j<52;j++){
            map[i][j] = "\n";
        }
    }
    
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i+1][j+1] = storage[i][j];
        }
    }
    
    
    vector<pair<int,int>> rm;
    for(string req : requests){
        //지게차
        rm.clear();
        if(req.length() == 1){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(map[i][j] == req){
                        if(map[i+1][j] == "\n" || map[i-1][j] =="\n" || map[i][j+1] =="\n" || map[i][j-1]=="\n"){
                            cout << "remove : " << i << " " << j  << '\n';
                            answer++;
                            rm.push_back({i,j});
                        }
                    }
                }
            }
        }
        //크레인
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(map[i][j][0] == req[0]){
                        cout << "remove : " << i << " " << j  << '\n';
                        answer++;
                        rm.push_back({i,j});
                    }
                }
            }
        }
        
        for(auto a : rm){
            int i = a.first;
            int j = a.second;
            
            if(map[i+1][j] == "\n" || map[i-1][j] =="\n" || map[i][j+1] =="\n" || map[i][j-1]=="\n"){
                map[i][j] = "\n";
                dfs(i,j);
            }
            else{
                map[i][j] = "a";
            }
        }
//         vector<pair<int,int>> vecvec;
//         vector<pair<int,int>> toA;
//         for(auto a : rm){
//             int i = a.first;
//             int j = a.second;
//             if(map[i+1][j] == "\n" || map[i-1][j] =="\n" || map[i][j+1] =="\n" || map[i][j-1]=="\n"){
//                 map[i][j] = "\n";
//                 if(map[i+1][j] == "a") vecvec.push_back({i+1, j});
//                 if(map[i-1][j] == "a") vecvec.push_back({i-1, j});
//                 if(map[i][j+1] == "a") vecvec.push_back({i, j+1});
//                 if(map[i][j-1] == "a") vecvec.push_back({i, j-1});
//             }
//             else toA.push_back({i,j});
//         }
        
//         for(auto a : vecvec){
//             map[a.first][a.second] = "\n";
//         }
//         for(auto a : toA){
//             map[a.first][a.second] = "a";
//         }
        
//         vecvec.clear();
//         toA.clear();
    }
    
    return n*m - answer;
}