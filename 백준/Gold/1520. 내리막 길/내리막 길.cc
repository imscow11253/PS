#include <iostream>

using namespace std;

int M,N;
int** arr;
int** DP;

int search(int row, int col){
    if(row == M && col == N) {DP[row][col] =1; return 1;}
    if(DP[row][col] != -1) return DP[row][col];
    else{
        DP[row][col] =0;
        if(arr[row-1][col] < arr[row][col]) DP[row][col] += search(row-1,col);
        if(arr[row][col-1] < arr[row][col]) DP[row][col] += search(row,col-1);
        if(arr[row][col+1] < arr[row][col]) DP[row][col] += search(row,col+1);
        if(arr[row+1][col] < arr[row][col]) DP[row][col] += search(row+1,col);
        return DP[row][col];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N;
    arr = new int*[M+2];
    DP = new int*[M+2];
    for(int i =0;i<M+2;i++){
        arr[i] = new int[N+2];
        DP[i] = new int[N+2];
        fill(arr[i], arr[i]+N+2, 10000);
        fill(DP[i], DP[i]+N+2,-1);
    }
    
    for(int i =1;i<M+1;i++){
        for(int j=1;j<N+1;j++) cin >> arr[i][j];
    }
    
    search(1,1);
    cout << DP[1][1] << '\n';
    
    /*for(int i=0;i<M+2;i++){
        for(int j=0;j<N+2;j++) cout << DP[i][j] << " ";
        cout << '\n';
    }*/

    for(int i=0;i<M+2;i++) {delete[] arr[i]; delete[] DP[i];}
    delete[] arr; delete[] DP;

    return 0;
}