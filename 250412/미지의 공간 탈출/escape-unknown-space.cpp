#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <stdlib.h>

using namespace std;

struct Weather{
    int row;
    int col;
    int direction;
    int period;
};

int n,m,f;
int flat_map[20][20] = {0,};
int cube_map[30][30] = {0,};
int destination_row, destination_col;
int cube_row, cube_col;
vector<Weather> vec;

int time_to_cube_escape;
int time_machine_row, time_machine_col;
int cube_escape_row, cube_escape_col;
int cube_escape_direction;

int total_time_to_escape;
pair<int,int> index_direction[4] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void flat_map_escape(){
    queue<tuple<int,int,int>> qu;
    bool visit[20][20] = {0,};
    qu.push(make_tuple(cube_escape_row, cube_escape_col, time_to_cube_escape));
    visit[cube_escape_row][cube_escape_col] = true;

    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();

        int row = get<0>(a);
        int col = get<1>(a);
        int time = get<2>(a);

        // cout << row << " " << col << " " << time << '\n';

        if(row == destination_row && col == destination_col){
            total_time_to_escape = time;
            return ;
        }

        bool check =0;
        //이상 기후로 막히는 경우
        for(auto weather : vec){
            int move = time/weather.period;
            int weather_row = weather.row;
            int weather_col = weather.col;
            if(weather_row == row && weather_col == col){
                check = true;
                break;
            }
            for(int i =0;i<move;i++){
                weather_row += index_direction[weather.direction].first;
                weather_col += index_direction[weather.direction].second;
                if(weather_row == row && weather_col == col){
                    check = true;
                    break;
                }
            }
            if(check) break;
        }

        if(check) continue;

        //상하좌우 이동
        if(row -1 >=0 && (flat_map[row-1][col] == 0 || flat_map[row-1][col]==4) && !visit[row-1][col]){
            qu.push(make_tuple(row-1, col, time+1));
            visit[row-1][col] = true;
        }
        if(row +1 < n && (flat_map[row+1][col] == 0 || flat_map[row+1][col]==4)&& !visit[row+1][col]){
            qu.push(make_tuple(row+1, col, time+1));
            visit[row+1][col] = true;
        }
        if(col -1 >=0 && (flat_map[row][col-1] ==0|| flat_map[row][col-1]==4) && !visit[row][col-1]){
            qu.push(make_tuple(row, col-1, time+1));
            visit[row][col-1] = true;
        }
        if(col +1 < n && (flat_map[row][col+1] ==0 || flat_map[row][col+1]==4)&& !visit[row][col+1]){
            qu.push(make_tuple(row, col+1, time+1));
            visit[row][col+1] = true;
        }
    }

    total_time_to_escape = -1;
}

void find_cube_escape_location(){
    for(int i =cube_col; i<cube_col+m;i++){
        if(cube_row-1 >=0 && flat_map[cube_row-1][i] == 0){
            cube_escape_row = cube_row -1;
            cube_escape_col = i;
            cube_escape_direction = 3;
            return;
        }
        if(cube_row+1 < n && flat_map[cube_row+m][i] == 0){
            cube_escape_row = cube_row +m;
            cube_escape_col = i;
            cube_escape_direction = 2;
            return;
        }
    }

    for(int i =cube_row; i<cube_row+m;i++){
        if(cube_col-1 >=0 && flat_map[i][cube_col-1] == 0){
            cube_escape_row = i;
            cube_escape_col = cube_col-1;
            cube_escape_direction = 1;
            return;
        }
        if(cube_col+1 < n && flat_map[i][cube_col+m] == 0){
            cube_escape_row = i;
            cube_escape_col = cube_col+m;
            cube_escape_direction = 0;
            return;
        }
    }
}

void cube_escape(){
    queue<tuple<int,int,int>> qu;
    bool visit[30][30]={0,};
    qu.push(make_tuple(time_machine_row, time_machine_col, 0));
    visit[time_machine_row][time_machine_col] = true;

    while(!qu.empty()){
        auto a = qu.front();
        qu.pop();

        int row = get<0>(a);
        int col = get<1>(a);
        int time = get<2>(a);

        // cout << row << " " << col<< " " << time << '\n';

        switch(cube_escape_direction){
            case 0:
                if(col == 10+m+m-1 && row-10+cube_row == cube_escape_row){
                    time_to_cube_escape = time+1;
                    return;
                }
                break;
            case 1:
                if(col == 10-m && row-10+cube_row == cube_escape_row){
                    time_to_cube_escape = time+1;
                    return;
                }
                break;  
            case 2:
                if(row == 10+m+m-1 && col-10+cube_col == cube_escape_col){
                    time_to_cube_escape = time+1;
                    return;
                }
                break;
            case 3:
                if(row == 10-m && col-10+cube_col == cube_escape_col){
                    time_to_cube_escape = time+1;
                    return;
                }
                break;
        }

        if(row -1 >=0 && cube_map[row-1][col] == 0 && !visit[row-1][col]){
            qu.push(make_tuple(row-1,col,time+1));
            visit[row-1][col] = true;
        }
        if(row +1 < 10+m+m && cube_map[row+1][col] == 0 && !visit[row+1][col]){
            qu.push(make_tuple(row+1,col,time+1));
            visit[row+1][col] = true;
        }
        if(col -1 >=0 && cube_map[row][col-1] == 0 && !visit[row][col-1]){
            qu.push(make_tuple(row,col-1,time+1));
            visit[row][col-1] = true;
        }
        if(col + 1 < 10+m+m && cube_map[row][col+1] == 0 && !visit[row][col+1]){
            qu.push(make_tuple(row,col+1,time+1));
            visit[row][col+1] = true;
        }

        //맞닿는 면 case 추가하기
        //서쪽면 상
        if(row == 10 && col >= 10 - m && col < 10){
            if(cube_map[10-(10-col)][10] == 0 && !visit[10-(10-col)][10]){
                qu.push(make_tuple(10-(10-col), 10, time+1));
                visit[10-(10-col)][10] = true;
            }
        }
        //서쪽면 하
        if(row == 10+m-1 && col >= 10 - m && col < 10){
            if(cube_map[10+m-1+(10-col)][10] == 0 && !visit[10+m-1+(10-col)][10]){
                qu.push(make_tuple(10+m-1+(10-col), 10, time+1));
                visit[10+m-1+(10-col)][10] = true;
            }
        }
        //남쪽면 좌
        if(col == 10 && row >= 10 + m && row < 10+m+m){
            if(cube_map[10+m-1][10-(row-(10+m-1))] == 0 && !visit[10+m-1][10-(row-(10+m-1))]){
                qu.push(make_tuple(10+m-1, 10-(row-(10+m-1)), time+1));
                visit[10+m-1][10-(row-(10+m-1))] = true;
            }
        }
        //남쪽면 우
        if(col == 10+m-1 && row >= 10 + m && row < 10+m+m){
            if(cube_map[10+m-1][10+m-1+(row-(10+m-1))] == 0 && !visit[10+m-1][10+m-1+(row-(10+m-1))]){
                qu.push(make_tuple(10+m-1, 10+m-1+(row-(10+m-1)), time+1));
                visit[10+m-1][10+m-1+(row-(10+m-1))] = true;
            }
        }
        //동쪽면 하
        if(row == 10+m-1 && col >= 10 + m && col < 10+m+m){
            if(cube_map[10+m-1+(col-(10+m-1))][10+m-1] == 0 && !visit[10+m-1+(col-(10+m-1))][10+m-1]){
                qu.push(make_tuple(10+m-1+(col-(10+m-1)), 10+m-1, time+1));
                visit[10+m-1+(col-(10+m-1))][10+m-1] = true;
            }
        }
        //동쪽면 상
        if(row == 10 && col >= 10 + m && col < 10+m+m){
            if(cube_map[10-(col-(10+m-1))][10+m-1] == 0 && !visit[10-(col-(10+m-1))][10+m-1]){
                qu.push(make_tuple(10-(col-(10+m-1)), 10+m-1, time+1));
                visit[10-(col-(10+m-1))][10+m-1] = true;
            }
        }
        //북쪽면 우
        if(col == 10+m-1 && row >= 10-m && row < 10){
            if(cube_map[10][10+m-1+(10-row)] == 0 && !visit[10][10+m-1+(10-row)]){
                qu.push(make_tuple(10, 10+m-1+(10-row), time+1));
                visit[10][10+m-1+(10-row)] = true;
            }
        }
        //북쪽면 좌
        if(col == 10 && row >= 10-m && row < 10){
            if(cube_map[10][10-(10-row)] == 0 && !visit[10][10-(10-row)]){
                qu.push(make_tuple(10, 10-(10-row), time+1));
                visit[10][10-(10-row)] = true;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> f;
    bool check =0;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> flat_map[i][j];
            if(flat_map[i][j]== 4){
                destination_row = i;
                destination_col = j;
            }
            if(!check && flat_map[i][j] == 3){
                cube_row = i;
                cube_col = j;
                check=1;
            }
        }
    }

    //cube map 초기화
    for(int i =0;i<30;i++){
        for(int j=0;j<30;j++){
            cube_map[i][j] = -1;
        }
    }

    //동쪽 입력
    for(int i=0;i<m;i++){
        for(int j =0;j<m;j++){
            cin >> cube_map[10+m-1-j][10+m+i];
        }
    }

    //서쪽 입력
    for(int i=0;i<m;i++){
        for(int j =0;j<m;j++){
            cin >> cube_map[10+j][10-1-i];
        }
    }

    //남쪽 입력
    for(int i=0;i<m;i++){
        for(int j =0;j<m;j++){
            cin >> cube_map[10+m+i][10+j];
        }
    }

    //북쪽 입력 
    for(int i=0;i<m;i++){
        for(int j =0;j<m;j++){
            cin >> cube_map[10-1-i][10+m-1-j];
        }
    }

    //윗면 입력
    for(int i=0;i<m;i++){
        for(int j =0;j<m;j++){
            cin >> cube_map[10+i][10+j];
            if(cube_map[10+i][10+j] == 2){
                time_machine_row = 10+i;
                time_machine_col = 10+j;
            }
        }
    }

    // for(int i =7;i<16;i++){
    //     for(int j=7;j<16;j++){
    //         cout << cube_map[i][j] <<  " "; 
    //     }cout << '\n';
    // }
    
    //이상 기후 입력
    int a,b,c,d;
    while(f--){
        cin >> a >> b >> c >> d;
        Weather temp;
        temp.row = a;
        temp.col = b;
        temp.direction = c;
        temp.period = d;
        vec.push_back(temp);
    }

    //큐브 탈출로 찾기 
    find_cube_escape_location();

    // cout << cube_row << " " << cube_col << '\n';
    // cout << cube_escape_row << " " << cube_escape_col << '\n';

    //큐브 탈출 
    cube_escape();
    // cout << time_to_cube_escape << '\n';

    //탈출하기
    flat_map_escape();
    cout << total_time_to_escape << '\n';

    return 0;
}