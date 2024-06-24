#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int N, cnt=0;

bool check(int &row, int& col){
    for(int i=0;i<row;i++){ // vec의 모든 요소 탐방
        if(col == vec[i] || abs(vec[i]-col) == row-i) return false; // 같은 열에 있는 것들, 대각선 check 
    }
    return true;
}

void checkQ(int row){
    if(row == N) cnt++;
    else{
        for(int col=0;col<N;col++){
            if(check(row, col)){
                vec.push_back(col);
                checkQ(row+1);
                vec.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    checkQ(0);
    cout << cnt;
    
    return 0;
}