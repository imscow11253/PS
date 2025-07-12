#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

struct Shark{ //row, col, speed, direction, size, time
    int r;
    int c;
    int s;
    int d;
    int z;
    int t;
};

int n,m,num;
Shark arr[101][101];
set<pair<int,int>> sharks;
unordered_map<int, int> topShark;
int result =0;

void simul(){
    for(int location =1;location<= m; location++){
        // cout << "==========================\n";
        // for(const auto& a : sharks){
        //     cout << a.first << " " << a.second<< '\n';
        // }
        
        //상어 잡기
        if(topShark.find(location) != topShark.end()){
            // cout << "caught : " << topShark[location]  << " " << location << '\n';
            result += arr[topShark[location]][location].z;
            sharks.erase({topShark[location], location});
            arr[topShark[location]][location] = {0,0,0,0,0};
        }
        
        //상어 이동
        map<pair<int,int>, Shark> temp;
        for(const auto &shark : sharks){
            int row = shark.first;
            int col = shark.second;
            auto &sharkStruct = arr[row][col];
            int speed = sharkStruct.s;
            int direction = sharkStruct.d;
            int size = sharkStruct.z;
            int _time = sharkStruct.t;
            
            // cout << "old : " << row << " " << col << '\n';
            
            switch(direction){
                case 1:
                    while(row > 1 && speed > 0){
                        row--;
                        speed--;
                    }
                    if(speed > 0) direction = 2;
                    while(row < n && speed > 0){
                        row++;
                        speed--;
                    }
                    if(speed > 0) direction = 1;
                    while(speed > 0){
                        row--;
                        speed--;
                    }
                    break;
                case 2:
                    while(row < n && speed > 0){
                        row++;
                        speed--;
                    }
                    if(speed > 0) direction = 1;
                    while(row > 1 && speed > 0){
                        row--;
                        speed--;
                    }
                    if(speed > 0) direction = 2;
                    while(speed > 0){
                        row++;
                        speed--;
                    }
                    break;
                case 3:
                    while(col < m && speed > 0){
                        col++;
                        speed--;
                    }
                    if(speed > 0) direction = 4;
                    while(col > 1 && speed > 0){
                        col--;
                        speed--;
                    }
                    if(speed > 0) direction = 3;
                    while(speed > 0){
                        col++;
                        speed--;
                    }
                    break;
                case 4:
                    while(col > 1 && speed > 0){
                        col--;
                        speed--;
                    }
                    if(speed > 0) direction = 3;
                    while(col < m && speed > 0){
                        col++;
                        speed--;
                    }
                    if(speed > 0) direction = 4;
                    while(speed > 0){
                        col--;
                        speed--;
                    }
                    break;
            }
            
            if(temp.find({row,col}) == temp.end()) temp.insert({{row,col}, {row,col,sharkStruct.s,direction,size,_time+1}});
            else {
                if(temp[{row,col}].z < size) temp[{row,col}] = {row,col,sharkStruct.s,direction,size,_time+1};
            }
            
            // cout << "new : " << row << " " << col << '\n';
        }
        sharks.clear();
        topShark.clear();
        for(const auto& kv : temp){
            int row = kv.first.first;
            int col = kv.first.second;
            arr[row][col] = kv.second;
            sharks.insert({row,col});
            if(topShark.find(col) == topShark.end()) topShark[col] = row;
            else topShark[col] = min(topShark[col], row);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> num;
    int r,c,s,d,z;
    for(int i =0;i<num;i++){
        cin >> r >> c >> s >> d >> z;
        if(d < 3) s %= ((n*2)-2);
        else s %= ((m*2)-2);
        // cout << r << " " << c << " " << s << '\n';
        arr[r][c] = {r,c,s,d,z};
        sharks.insert({r,c});
        if(topShark.find(c) == topShark.end()) topShark[c] = r;
        else topShark[c] = min(topShark[c], r);
    }
    
    simul();
    cout << result;
    
    return 0;
}
