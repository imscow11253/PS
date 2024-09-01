#include <iostream>

using namespace std;

int arr[15][15]={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i =1;i<15;i++){
        arr[0][i] = i;
    }
    
    for(int i =1;i<15;i++){
        for(int j=1;j<15;j++){
            for(int k=1;k<=j;k++){
                arr[i][j] += arr[i-1][k];
            }
        }
    }
    
    // for(int i =1;i<15;i++){
    //     for(int j=1;j<15;j++){
    //         cout << arr[i][j] << " ";
    //     }cout << '\n';
    // }
    
    int t;
    cin >> t;
    
    int k,n;
    while(t--){
        cin >> k >> n;
        cout << arr[k][n] << '\n';
    }
    
    return 0;
}