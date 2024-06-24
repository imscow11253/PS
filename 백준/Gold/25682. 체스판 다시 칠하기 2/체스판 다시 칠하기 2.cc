#include <iostream>

using namespace std;
// 직접 짠 코드드
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    char temp;
    int Barr[N+1][M+1]{};
    int Warr[N+1][M+1]{};
    
    for(int i =1;i<N+1;i++){
        for(int j=1;j<M+1;j++){
            cin >> temp;
            if(i%2 == 0 && j%2 == 0){
                if(temp == 'B') Warr[i][j]++;
                else Barr[i][j]++;
            }
            else if(i%2 == 1 && j%2 == 1){
                if(temp == 'B') Warr[i][j]++;
                else Barr[i][j]++;
            }
            else {
                if(temp == 'B') Barr[i][j]++;
                else Warr[i][j]++;
            }
            Barr[i][j] += Barr[i-1][j] + Barr[i][j-1] - Barr[i-1][j-1];
            Warr[i][j] += Warr[i-1][j] + Warr[i][j-1] - Warr[i-1][j-1];
        }
    }
    
    
    /*cout << "=================\n";
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) cout << Barr[i][j] << " ";
        cout << '\n';
    }
    cout << "=================\n";
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) cout << Warr[i][j] << " ";
        cout << '\n';
    }*/
    
    int min=4000000, re; 
    for(int i=K;i<N+1;i++){
        for(int j=K;j<M+1;j++){
            re = Barr[i][j] - Barr[i-K][j] - Barr[i][j-K] + Barr[i-K][j-K];
            if(re < min) min = re;
            re = Warr[i][j] - Warr[i-K][j] - Warr[i][j-K] + Warr[i-K][j-K];
            if(re < min) min = re;
        }
    }

    cout << min;
    return 0;
}