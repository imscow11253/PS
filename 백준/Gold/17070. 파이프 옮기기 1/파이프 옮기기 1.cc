#include <iostream>
#include <tuple>
using namespace std;

int n;
int arr[16][16];
tuple<int,int,int> dp[16][16]; //가로, 대각, 세로

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    // 초기상태: (0,1)만 가로 방향 하나
    dp[0][1] = make_tuple(1,0,0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]==1) continue;
            int x = get<0>(dp[i][j]);
            int y = get<1>(dp[i][j]);
            int z = get<2>(dp[i][j]);
            //가로로 이동
            if(j+1<n && arr[i][j+1]==0)
                get<0>(dp[i][j+1]) += x + y;
            //대각선으로 이동
            if(i+1<n && j+1<n && arr[i+1][j]==0 && arr[i][j+1]==0 && arr[i+1][j+1]==0)
                get<1>(dp[i+1][j+1]) += x + y + z;
            //세로로 이동
            if(i+1<n && arr[i+1][j]==0)
                get<2>(dp[i+1][j]) += y + z;
        }
    }
    int res = get<0>(dp[n-1][n-1]) + get<1>(dp[n-1][n-1]) + get<2>(dp[n-1][n-1]);
    cout << res << '\n';
}