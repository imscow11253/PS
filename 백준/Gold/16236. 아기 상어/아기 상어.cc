#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cstring>

using namespace std;

struct compare {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        if (get<2>(a) != get<2>(b)) {
            return get<2>(a) > get<2>(b);
        }
        if (get<0>(a) != get<0>(b)) {
            return get<0>(a) > get<0>(b);
        }
        return get<1>(a) > get<1>(b);
    }
};

int n;
int arr[20][20] = {0,};
pair<int,int> shark;
int result=0;
int sharkSize=2;
int ate =0;
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, compare> pq;

void bfs(){
    queue<tuple<int,int,int>> qu; //i,j,distance;
    bool visit[20][20] = {0,};
    
    qu.push(make_tuple(shark.first, shark.second, 0));
    visit[shark.first][shark.second] = true;
    
    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();
        
        int row = get<0>(a);
        int col = get<1>(a);
        int distance = get<2>(a);
        
        if(arr[row][col] != 0 && arr[row][col] < sharkSize){
            pq.push(make_tuple(row,col, distance));
        }
        
        if(row-1 >= 0 && !visit[row-1][col] && arr[row-1][col] <= sharkSize){
            qu.push(make_tuple(row-1, col, distance+1));
            visit[row-1][col] = true;
        }
        if(col-1 >= 0 && !visit[row][col-1] && arr[row][col-1] <= sharkSize){
            qu.push(make_tuple(row, col-1, distance+1));
            visit[row][col-1] = true;
        }
        if(row+1 < n && !visit[row+1][col] && arr[row+1][col] <= sharkSize){
            qu.push(make_tuple(row+1, col, distance+1));
            visit[row+1][col] = true;
        }
        if(col+1 < n && !visit[row][col+1] && arr[row][col+1] <= sharkSize){
            qu.push(make_tuple(row, col+1, distance+1));
            visit[row][col+1] = true;
        }
    }
}

void find(){
    do{
        while(!pq.empty()) pq.pop();
        bfs();
        if(pq.empty()) break;
        
        auto a = pq.top();
        
        int row = get<0>(a);
        int col = get<1>(a);
        int distance = get<2>(a);
        
        // cout << row << " " << col << " " << distance <<'\n';
        
        result += distance;
        arr[row][col] = 0;
        shark = {row, col};
        ate++;
        if(ate == sharkSize){
            sharkSize += 1;
            ate =0;
        }
    }while(!pq.empty());
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9) {shark = {i,j}; arr[i][j] = 0;}
        }
    }
    
    find();
    cout << result;
    
    return 0;
}