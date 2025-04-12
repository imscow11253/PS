#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int k,m;
int treasure[5][5] = {0,};
queue<int> next_treasure;

bool visit[5][5] = {0,};
int simul_pan[5][5] = {0,};
int result=0;

set<pair<int,int>> delete_set;

void initial_visit(){
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            visit[i][j] =0;
        }
    }
}

void initial_simul_pan(){
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            simul_pan[i][j] =0;
        }
    }
}

void delete_dfs(int row, int col){
    visit[row][col] = true;
    delete_set.insert({row,col});
    if(row -1 >=0 && treasure[row-1][col] == treasure[row][col] && !visit[row-1][col]){
        delete_dfs(row-1,col);
    }
    if(row +1 < 5 && treasure[row+1][col] == treasure[row][col] && !visit[row+1][col]){
        delete_dfs(row+1,col);
    }
    if(col - 1 >=0 && treasure[row][col-1] == treasure[row][col] && !visit[row][col-1]){
        delete_dfs(row,col-1);
    }
    if(col+ 1 < 5 && treasure[row][col+1] == treasure[row][col] && !visit[row][col+1]){
        delete_dfs(row,col+1);
    }
}

int delete_simul(){
    initial_visit();
    int delete_result =0;
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            if(visit[i][j]) continue;
            delete_dfs(i,j);
            if(delete_set.size() >= 3){
                for(auto a : delete_set){
                    treasure[a.first][a.second] = 0;
                    delete_result++;
                }
            }
            delete_set.clear();
        }
    }
    return delete_result;
}

void block_dfs(int row, int col){
    visit[row][col] = true;
    result++;
    if(row -1 >=0 && simul_pan[row-1][col] == simul_pan[row][col] && !visit[row-1][col]){
        block_dfs(row-1,col);
    }
    if(row +1 < 5 && simul_pan[row+1][col] == simul_pan[row][col] && !visit[row+1][col]){
        block_dfs(row+1,col);
    }
    if(col - 1 >=0 && simul_pan[row][col-1] == simul_pan[row][col] && !visit[row][col-1]){
        block_dfs(row,col-1);
    }
    if(col+ 1 < 5 && simul_pan[row][col+1] == simul_pan[row][col] && !visit[row][col+1]){
        block_dfs(row,col+1);
    }
}

int simul(){
    
    initial_visit();

    int value=0;
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            if(visit[i][j]) continue;
            result =0;
            block_dfs(i,j);
            if(result >= 3){
                value += result;
            }
        }
    }
    return value;
}

pair<int,int> spin_simul(int row, int col){
    pair<int,int> simul_result;
    //90도 회전
    initial_simul_pan();
    for(int i=row-1; i<=row+1;i++){
        for(int j=col-1; j<=col+1;j++){
            simul_pan[i][j] = treasure[row+1-(j-(col-1))][i-(row-1)+col-1];
        }
    }
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            if(simul_pan[i][j] == 0) simul_pan[i][j] = treasure[i][j];
        }
    }
    int block_num = simul();
    simul_result.first = block_num;
    simul_result.second = 1;

    //180도 회전
    initial_simul_pan();
    for(int i=row-1; i<=row+1;i++){
        for(int j=col-1; j<=col+1;j++){
            simul_pan[i][j] = treasure[row+1-(i-(row-1))][col+1-(j-(col-1))];
        }
    }
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            if(simul_pan[i][j] == 0) simul_pan[i][j] = treasure[i][j];
        }
    }
    block_num = simul();
    if(block_num > simul_result.first){
        simul_result.first = block_num;
        simul_result.second = 2;
    }

    //270도 회전
    initial_simul_pan();
    for(int i=row-1; i<=row+1;i++){
        for(int j=col-1; j<=col+1;j++){
            simul_pan[i][j] = treasure[row-1+(j-(col-1))][col+1-(i-(row-1))];
        }
    }
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            if(simul_pan[i][j] == 0) simul_pan[i][j] = treasure[i][j];
        }
    }
    block_num = simul();
    if(block_num > simul_result.first){
        simul_result.first = block_num;
        simul_result.second = 3;
    }

    return simul_result;
}

void real_rotate(int row, int col, int rotate_num){
    initial_simul_pan();
    for(int k =0;k<rotate_num;k++){
        for(int i=row-1; i<=row+1;i++){
            for(int j=col-1; j<=col+1;j++){
                simul_pan[i][j] = treasure[row+1-(j-(col-1))][i-(row-1)+col-1];
                // cout << "change : {" << row+1-(j-(col-1)) << ", " << i-(row-1)+col-1 << "} to {" << i << ", " <<j << "}\n";
            }
        }
        for(int i=row-1; i<=row+1;i++){
            for(int j=col-1; j<=col+1;j++){
                treasure[i][j] = simul_pan[i][j];
            }
        }

        // for(int i=row-1; i<=row+1;i++){
        //     for(int j=col-1; j<=col+1;j++){
        //         cout << simul_pan[i][j] << " ";
        //     }cout << '\n';
        // }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> m;
    for(int i =0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> treasure[i][j];
        }
    }

    int temp;
    while(m--){
        cin >> temp;
        next_treasure.push(temp);
    }

    while(k--){
        int total_value=0;

        //돌려보고 최적의 선택 찾기 
        pair<int,int> simul_result_map[5][5];

        for(int i = 1;i<4;i++){
            for(int j=1;j<4;j++){
                auto a = spin_simul(i,j);
                simul_result_map[i][j] = a;
            }
        }

        // for(int i = 1;i<4;i++){
        //     for(int j=1;j<4;j++){
        //         cout << "{" << simul_result_map[i][j].first << ", " << simul_result_map[i][j].second << "} ";
        //     }cout << '\n';
        // }

        //아무것도 spin 안할 때도 계산해보기
        initial_simul_pan();
        for(int i =0;i<5;i++){
            for(int j=0;j<5;j++){
                simul_pan[i][j] = treasure[i][j];
            }
        }
        int none_rotate = simul();

        //최적의 회전 option 선택하기
        pair<int,int> optimal_pair = {0,0};
        int optimal_row;
        int optimal_col;
        for(int i = 1;i<4;i++){
            for(int j=1;j<4;j++){
                if(optimal_pair.first < simul_result_map[i][j].first){
                    // cout << "optinal change to " << i << " " << j << '\n';
                    optimal_pair = simul_result_map[i][j];
                    optimal_row = i;
                    optimal_col = j;
                }
                else if(optimal_pair.first == simul_result_map[i][j].first){
                    if(optimal_pair.second > simul_result_map[i][j].second){
                        // cout << "optinal change to by rotate " << i << " " << j << '\n';
                        optimal_pair = simul_result_map[i][j];
                        optimal_row = i;
                        optimal_col = j;
                    }
                }
            }
        }

        // cout << optimal_row << " " << optimal_col << '\n';

        if(optimal_pair.first <= none_rotate){
            //nothing
        }
        else if(optimal_pair.second == 0){
            return 0;
        }
        else{
            //실제로 rotate 하기 
            real_rotate(optimal_row, optimal_col, optimal_pair.second);
        }

        // for(int i=0;i<5;i++){
        //     for(int j =0;j<5;j++) cout << treasure[i][j];
        //     cout << '\n';
        // }

        //dfs로 삭제하기
        total_value += delete_simul();

        //채워넣기
        for(int i =0;i<5;i++){
            for(int j=4;j>=0;j--){
                if(treasure[j][i] == 0){
                    treasure[j][i] = next_treasure.front();
                    next_treasure.pop();
                }
            }
        }

        // for(int i=0;i<5;i++){
        //     for(int j =0;j<5;j++) cout << treasure[i][j];
        //     cout << '\n';
        // }

        int delete_result = delete_simul();
        total_value += delete_result;
        while(delete_result != 0){
            //채워넣기
            for(int i =0;i<5;i++){
                for(int j=4;j>=0;j--){
                    if(treasure[j][i] == 0){
                        treasure[j][i] = next_treasure.front();
                        next_treasure.pop();
                    }
                }
            }
            //다시 지워보기
            delete_result = delete_simul();
            total_value += delete_result;
        }

        //지운 가치 출력
        if(total_value ==0) return 0;
        cout << total_value << " ";
    }


    return 0;
}