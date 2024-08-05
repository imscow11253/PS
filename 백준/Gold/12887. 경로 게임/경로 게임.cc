#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int m;
char arr[2][50];
int black=0;
int result=0;

void travel(int a , int b){
    int check[2][50] = {{}};
    // cout << a << " " << b << '\n';
    // for(int i =0;i<2;i++){
    //     for(int j=0;j<m;j++){
    //         cout << check[i][j] << " ";
    //     }cout << '\n';
    // }
    queue<tuple<int,int,int>> qu;
    qu.push({a,b,0});
    
    while(!qu.empty()){
        auto position = qu.front();
        qu.pop();
        
        int row = get<0>(position);
        int col = get<1>(position);
        int node = get<2>(position);
        // cout << row << " " << col << '\n';
        
        int cnt=0;
        if(col == m-1){
            // cout << "================\n";
            // for(auto a : st){
            //     cout << "{ " << a.first << ", " << a.second << " }, ";
            // }cout << '\n';
            
            // for(int i =0;i<2;i++){
            //     for(int j=0;j<m;j++){
            //         if(arr[i][j] == '.' && st.find({i,j}) == st.end()){
            //             // cout << i << " " << j << '\n';
            //             cnt++;
            //         }
            //     }
            // }
            // cout << 2*m << " " << result << " " << black << '\n';
            if(result < 2*m - node -1  - black) result = 2*m - node -1  - black;
            return;
        }
        
        if(row ==0){
            if(arr[row+1][col] == '.' && !check[row+1][col]) {
                qu.push({row+1, col, node+1});
                check[row+1][col] =1;
            }
        }
        else{
            if(arr[row-1][col] == '.' && !check[row-1][col]) {
                qu.push({row-1, col, node+1});
                check[row-1][col] =1;
            }
        }
        
        if(arr[row][col+1] == '.' && !check[row][col+1]) {
            qu.push({row, col+1, node+1});
            check[row][col+1] =1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin >> m;
    
    string str;
    for(int i=0;i<2;i++){
        cin >> str;
        for(int j=0;j<m;j++){
            arr[i][j] = str[j];
            if(str[j] == '#') black++;
        }
    }
    
    if(arr[0][0] == '.') {
         travel(0,0);
    }
    if(arr[1][0] == '.') {
         travel(1,0);
    }
    cout <<result;
    
    return 0;
}